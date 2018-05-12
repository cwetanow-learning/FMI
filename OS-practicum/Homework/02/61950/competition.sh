#!/bin/bash

directory=$1

if [ ! -d "$directory" ]; then
  echo "Directory does not exist"
  exit 1
fi

function=$2

participants=$(ls -l $directory | tail -n +2 | rev | cut -d ' ' -f1 | rev)

#a
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
#c
elif [ $function = "unique" ];
then
  echo "Not implemented"
#d
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

#b
