#!/bin/bash

array=()
array+=("f")
array+=("b")

array+=("b"
        "c"
        "d")

for i in {1..3}; do 
    array+=($RANDOM)
done

buf=""
for i in ${array[@]}; do
    echo $i
    buf+=" $i"
done

# array=$buf
# echo "array: $array"

if [[ "${array[@]}" =~ "a" ]]; then
    echo "a in array"
else
    echo "a not in array"
fi

buf=("a" "b")
if [[ $buf =~ "b" ]]; then
    echo "a in array"
else
    echo "a not in array"
fi
unset buf

echo $buf

buf=("a" "b")

echo $buf