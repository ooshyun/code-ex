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


for python_version in {6..8}
do
    if [ $python_version -eq 6 ]; then
        echo "python_version is 6"
    else
        echo "python_version is above 6"
    fi
done 

test_str="abcd"

if [ $test_str = "abc" ]
then
    echo "test_str is abc"
elif [ $test_str = "abcd" ]
then
    echo "test_str is abcd"
else
    echo "test_str is not abc"
fi


if [ $test_str != "abc" ]
then
    echo "test_str is not abc"
fi

function iftest() {
    if [ -z "$1" ]; then
        echo "No argument supplied"
    else
        if [ $1 -eq 0 ]; then
            echo "First argument is 0"
        fi

        if [ $1 = "hello" ]; then
            echo "First argument is hello"
        fi
    fi

    echo "empty argument test"

    if [ ! -z $1 ] && [ $1 -eq 0 ]; then
        echo "First argument is 0"
    fi
    
    echo "end of empty argument test"
   
}

set -e
iftest
iftest 0
iftest hello

echo "Finshed"


# Define the list as an array
list=("apple" "banana" "cherry")

# The variable to check
item="bananaa"

# Flag to indicate if the item was found
found=false

# Loop through the array
for i in "${list[@]}"; do
  if [[ "$i" == "$item" ]]; then
    found=true
    break
  fi
done

# Check if the item was found
if [ "${found}" = true ]; then
  echo "$item is in the list."
else
  echo "$item is not in the list."
fi