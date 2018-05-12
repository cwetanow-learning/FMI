#!/bin/bash

directory=$1
function=$2

participants=$(ls -l $directory | tail -n +2 | rev | cut -d ' ' -f1 | rev)

for participant in $participants;
do
  cat "$directory/$participant" | egrep -v "$participants"
done

