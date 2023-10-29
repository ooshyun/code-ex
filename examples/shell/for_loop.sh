#!bin/bash

for i in {1..5}
do
    echo "Welcome $i times"
done

for i in {1..5}
do
    version=$(($i+1))
    echo "Welcome $version times"
done

set -e
for i in {1..3}
do 
    ls -l temp_$RANDOM
done