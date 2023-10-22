#!bin/bash

if [ $# -eq 0 ]
then
    echo "No arguments supplied"
fi


if [ $1 -eq 0 ]
then
    echo "First argument is 0"
fi

test1=2
declare -i test2=2
test3=$((2))

if [ $test1 -eq 2 ]
then
    echo "test1 variable is 2"
fi

if [ $test2 -eq 2 ]
then
    echo "test2 variable is 2"
fi

if [ $test3 -eq 2 ]
then
    echo "test2 variable is 2"
fi