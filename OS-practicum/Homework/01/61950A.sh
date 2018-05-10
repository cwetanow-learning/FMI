#!/bin/bash

is_letter=1
letter=''
cat secret_message > encrypted
sed -i -e 's/^/ /' encrypted
sed -i -e 's/$/ /' encrypted

sed -i "s/\./0/g" encrypted
sed -i "s/-/1/g" encrypted
sed -i "s/ /  /g" encrypted

morse=$(cat morse | sed "s/\./0/g" | sed "s/-/1/g"  )

for symbol in $morse;
do
  if [ $is_letter -eq 1 ]
  then
    is_letter=0
    letter=$symbol
  elif [ $is_letter -eq 0 ]
  then
    is_letter=1
    sed -i "s/ $symbol / $letter /g" encrypted
  fi
done

result=$(cat encrypted | tr '[:upper:]' '[:lower:]' | tr -d '[:space:]')

echo $result > encrypted