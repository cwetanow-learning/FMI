#!/bin/bash

all=$(find $1 -type f | wc -l)
uniq=$(fdupes -r $1 | egrep '^$' | wc -l)
allDuplicates=$(fdupes -r $1 | egrep -v '^$' | wc -l)
res=$(($all-$allDuplicates+$uniq))

echo "Count of unique files is $res"
echo "$all"
