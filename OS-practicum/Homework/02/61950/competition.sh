#!/bin/bash

directory=$1
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
fi

#b
