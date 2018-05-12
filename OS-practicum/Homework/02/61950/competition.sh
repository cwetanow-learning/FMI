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
fi

