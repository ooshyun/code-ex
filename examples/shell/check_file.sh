#!/bin/bash

FILE="/Users/seunghyunoh/workplace/examplace/practice/examples/shell/string_to_int.sh"
if [ -f "$FILE" ]; then
    echo "$FILE file exists."
else 
    echo "$FILE file does not exist."
fi

FILE+="a"
if [ -f "$FILE" ]; then
    echo "$FILE file exists."
else 
    echo "$FILE file does not exist."
fi

FILE=/Users/seunghyunoh/workplace/examplace/practice/examples/shell/
if [ -d "$FILE" ]; then
    echo "$FILE folder exists."
else 
    echo "$FILE folder does not exist."
fi

FILE+="a"
if [ -d "$FILE" ]; then
    echo "$FILE folder exists."
else 
    echo "$FILE folder does not exist."
fi
