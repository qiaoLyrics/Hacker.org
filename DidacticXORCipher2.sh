#!/bin/sh


for i in {160..255} ; do 
	while read -n 2 var ; do 
		var=$(echo "ibase=16;$var"  | bc)
		((var=var^i))
		echo $var | awk ' { printf("%c", $var) ; } '
	done < $1
	echo ""
done 
