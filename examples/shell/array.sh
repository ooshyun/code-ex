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


# Simulate nested arrays using strings
# Each 'array' is a space-separated string
nested_array="a1 a2 a3:b1 b2 b3:c1 c2 c3"

# Outer loop to iterate over the 'outer' array (the string representing nested arrays)
IFS=':' # Internal Field Separator for the outer array
set -f  # Disable glob expansion to safely handle *
for outer_element in $nested_array; do
    
    # Inner loop to iterate over the 'inner' array (elements within each nested array)
    IFS=' ' # Internal Field Separator for the inner array
    for inner_element in $outer_element; do
        echo "$inner_element"
    done
done
set +f  # Re-enable glob expansion