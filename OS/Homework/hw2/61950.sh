#!/bin/bash

if [[ ! -d ${1} ]]; then 
	echo "Invalid directory"
	exit 1
fi

directories=$(find $1 -type d)

for dir in $directories;
do
	log_file="$dir.log"
	if [[ -f $log_file ]]; then
		counter=0
		declare -a jpeg_files
		while read line; do
			if [[ "$line" =~ .*.jpg$ ]]; then
				jpeg_files[$counter]=$line
				counter=$(expr $counter + 1)
			fi
		done< <(ls -rt "$dir")

		name=""
		line_counter=0
		counter=0
		location=""
		while read line; do
			if [[ -z $line ]]; then
				counter=$(expr $counter + 1 )
				line_counter=0;
				continue
			fi

			if [[ $line_counter -eq 0 ]]; then
				name=$(date +%FT%H%M -d "@$(echo ${line}|cut -d' ' -f1)")
				location=$(echo ${line} | cut -d ' ' -f2)
			elif [[ $line_counter -eq 1 ]]; then
				description=$(echo ${line} | tr '[:upper:]' '[:lower:]' | tr ' ' '_')

				name="$dir/${name}_${description}"
				old="$dir/${jpeg_files[$counter]}"

				mv $old $name
				#exiftool -Location="$location" > ${name}
			fi
			line_counter=$(expr $line_counter + 1)
		done< <(cat "$log_file")
	fi
done
