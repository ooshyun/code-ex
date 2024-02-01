#!bin/bash

# bool
x=true
if [ $x ]; then
    echo "x is true"
else
    echo "x is false"
fi

if [ "${x}" = true ]; then
    echo "x is true"
else
    echo "x is false"
fi

if [ "${x}" = "true" ]; then
    echo "x is true"
else
    echo "x is false"
fi