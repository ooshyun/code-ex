#!/bin/bash
g++ set.cc -std=c++14 -o set 

set -x  # debug, print all of the commands

# case 1
set +e # cont
# set -e # stop
echo "Hello"
aaa
echo "World"

# case 2
set +e  # cont
# set -e # stop

./set true
./set false

# ./set false cause error, +e will continute (e.g. print Finished)
# ./set true -e will stop (e.g. not print Finished)
echo "Finished" 


set -o pipefail
./set false
echo $? # grep exit code

set -o pipefail
false | true
echo $?

rm -rf set