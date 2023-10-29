#!bin/bash

FILENAME="./find_path.sh"

if [ -e "$FILENAME" ]; then
    echo "File $FILENAME exists."
else
    echo "File $FILENAME does not exist."
fi