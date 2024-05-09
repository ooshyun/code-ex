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

if [ ! -d "$FILE"  ]; then
    echo "$FILE folder does not exist."
else 
    echo "$FILE folder exists."
fi

FILE+="a"
if [ -d "$FILE" ]; then
    echo "$FILE folder exists."
else 
    echo "$FILE folder does not exist."
fi

folder="./test"

# Check if the folder contains any files
if [ "$(find "$folder" -type f -print -quit)" ]; then
    echo "Files exist in the folder."
else
    echo "No files in the folder."
fi

# Check if the folder contains any files
if [ "$(find "$folder" -type d -print -quit)" ]; then
    echo "Folder exist in the folder."
else
    echo "No Folder in the folder."
fi

test_bool=false
if [ test_bool ] && [ "$(find "$folder" -type f -print -quit)" ] || [ "$(find "$folder" -type d -print -quit)" ] ; then
    echo "Files exist in the folder."
else
    echo "No files in the folder."
fi
