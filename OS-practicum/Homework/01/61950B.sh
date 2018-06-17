#!/bin/bash

alphabet=abcdefghijklmnopqrstuvwxyz
phrase='fuehrer'

for counter in {1..25}
do
  code=$(echo $phrase | sed "y/${alphabet}/${alphabet:$counter}${alphabet::$counter}/")

  message=$(cat encrypted | egrep $code)

  if ! [[ -z $message ]]  
  then
    break    
  fi
done
(( counter=26-counter ))

echo $counter
cat encrypted | sed "y/${alphabet}/${alphabet:$counter}${alphabet::$counter}/"