#!bin/sh

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

supported_python_versions=( "6" "7" "8" )
for python_version in ${supported_python_versions[@]}
do
    echo "Building Python package for Python $python_version"
done

empty_array=()
# empty_array+=("a")
for i in ${empty_array[@]}; do
    echo "This will never be printed"
done

str_forloop=" This is a string"
for i in $str_forloop; do
    echo "This will be printed 4 times"
    echo $i
done

str_forloop="461543 461547"
for i in $str_forloop; do
    echo "This will be printed 2 times"
    echo $i
done


filename="example.py"

if [[ "$filename" == *.py ]]; then
    echo "The file is a Python script."
else
    echo "The file is not a Python script."
fi