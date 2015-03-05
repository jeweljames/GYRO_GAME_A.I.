
#!/bin/bash

dir=$(pwd)
slash='/'
for i in `seq 1 999`;
do
	file=try$i.jpg
	name=$dir$slash$file
    echo $name>>text.txt 
done 