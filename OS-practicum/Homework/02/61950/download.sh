#!/bin/bash
# ./download.sh test http://lzdx.bfra.bg/logs/2017

directory=$1

if [ ! -d "$directory" ]; then
  echo "Directory does not exist"
  exit 1
fi

url=$2
participants=$(curl "$url/" | egrep ">[A-Z0-9]*</a>" -o | tr -d ">" | tr -d "</a>")

for participant in $participants;
do
  participantUrl="$url/$participant";

  file="$directory/$participant";
  
  touch $file
  curl $participantUrl > $file
done