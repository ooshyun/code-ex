#!/bin/bash

# Space-separated string
MY_STRING="element1 element2 element3"

# Convert the string into an array
IFS=' ' read -r -a MY_ARRAY <<< "$MY_STRING"

# Now MY_ARRAY is an array, and you can iterate over it
for ELEMENT in "${MY_ARRAY[@]}"
do
    echo "Array element: $ELEMENT"
done