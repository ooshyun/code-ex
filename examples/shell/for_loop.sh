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
    echo $RANDOM
done


for NAME in "ME" "YOU" "THEM" "ALL"; do
    echo "Name is ${NAME}"
done

PLANETS=( "EARTH" "MARS" "VINUS" )
for PLANET in ${PLANETS[@]}; do
    echo "This is ${PLANET}"
done
for (( i=0; i<${#PLANETS[@]}; i++ )); do
    echo "Planet #$i is ${PLANETS[i]}"
done