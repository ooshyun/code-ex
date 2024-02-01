#!bin/bash

path="./tmp"
path="."
num_file=$(ls -1 $path | wc -l)
echo "Number of files in $path: $num_file"

if [ $num_file -eq 0 ]
then
    echo "No files in $path"
else
    echo "Files in $path:"
    ls -1 $path
fi

echo "----------------"

num_file_find=$(find $path -type f -name "*.sh*" | wc -l)

if [ $num_file_find -eq 0 ]
then
    echo "No files in $path with extension .sh"
else
    echo "Files in $path with extension $num_file_find including .sh:"
fi
