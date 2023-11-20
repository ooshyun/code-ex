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
}

iftest
iftest 0
iftest hello
