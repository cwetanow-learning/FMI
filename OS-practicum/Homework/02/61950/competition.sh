#!/bin/bash

directory=$1

if [ ! -d "$directory" ]; then
  echo "Directory does not exist"
  exit 1
fi

function=$2

participants=$(ls -l $directory | tail -n +2 | rev | cut -d ' ' -f1 | rev)

if [ $function = "participants" ]; 
then
  for participant in $participants;
  do
    echo $participant
  done
elif [ $function = "outliers" ];
then
  communications=""
  for participant in $participants;
  do
    codes=$(cat $directory/$participant | egrep "QSO" | sed "s/  \+/ /g" | cut -d " " -f 9)
    for code in $codes;
    do
    if [ ! -f "$directory/$code" ]; then
      if [[ ! $communications = *" $code "* ]]; then
        communications=$communications' '$code
      fi
    fi
    done
  done
  
  for false_communication in $communications;
  do
    echo $false_communication
  done
elif [ $function = "unique" ];
then
  declare -A logs

  for participant in $participants;
  do
    codes=$(cat $directory/$participant | egrep "QSO" | sed "s/  \+/ /g" | cut -d " " -f 9)

    for code in $codes;
    do
      if [ ! ${logs[$code]+abc} ]; then
        logs[$code]=1
      else
        logs[$code]=$(( logs[$code] + 1 ))
      fi
    done
  done

  for code in "${!logs[@]}"; do 
    if [ ${logs[$code]} -lt 4 ]; then
      echo $code
    fi  
  done
elif [ $function = "cross_check" ];
then
  for participant in $participants;
  do
    codes=$(cat $directory/$participant | egrep "QSO" | sed "s/  \+/ /g" | cut -d " " -f 9)

    for code in $codes;
    do
      if [ -f "$directory/$code" ]; then
        if ! grep -q $participant "$directory/$code"; then
          cat $directory/$participant | egrep $code    
        fi
      fi
    done
  done
else
  echo "Invalid function"
  exit 1
fi
