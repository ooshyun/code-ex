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


if [ $test_str != "abc" ]
then
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

    echo "empty argument test"

    if [ ! -z $1 ] && [ $1 -eq 0 ]; then
        echo "First argument is 0"
    fi
    
    echo "end of empty argument test"
}

set -e
iftest
iftest 0
iftest hello

echo "Finshed"


# Define the list as an array
list=("apple" "banana" "cherry")

# The variable to check
item="bananaa"

# Flag to indicate if the item was found
found=false

# Loop through the array
for i in "${list[@]}"; do
  if [[ "$i" == "$item" ]]; then
    found=true
    break
  fi
done

# Check if the item was found
if [ "${found}" = true ]; then
  echo "$item is in the list."
else
  echo "$item is not in the list."
fi

if [ "${found}" != true ]; then
  echo "$item is not in the list."
else 
  echo "$item is in the list."  
fi

# Initialize variables
counter=0
limit=5

echo "Initial counter value: $counter"

# Continue loop until counter reaches the limit
while [ $counter -lt $limit ]; do
    # Increment the counter
    counter=$((counter + 1))
    echo "Inside loop, counter value: $counter"
done

# After the loop
echo "Final counter value: $counter"


# # Get starting Unix time
# start_time=$(date +%s)

# # Define the duration in seconds for how long the loop should run
# duration=10 # This loop will run for 10 seconds

# # Calculate the end time
# end_time=$((start_time + duration))

# # Start the loop
# while [ $(date +%s) -lt $end_time ]; do
#     echo "Looping... Current time: $(date +%s)"
#     sleep 1 # Sleep for 1 second to prevent spamming
# done

# echo "Loop completed."



function check_list() {
  echo "Checking the list..."
  # Define the list as an array
  list=("apple" "banana" "cherry")

  # The variable to check
  item="banana"

  # Flag to indicate if the item was found
  found=false

  # Loop through the array
  for i in "${list[@]}"; do
    if [[ "$i" == "$item" ]]; then
      found=true
      return true
      break
    fi
  done  
  return false
}

test_x=false

if [ "${test_x}" = true ] || \
  [ ! check_list ]; then
  echo "test_x is true"
else
  echo "test_x is false"
fi

if [ check_list ]; then
  echo "test_x is true"
else
  echo "test_x is false"
fi

check_value() {
  local value=$1
  if [ "$value" -gt 10 ]; then
    return 0  # Indicates success
  else
    return # Indicates failure
  fi
}

echo "Test above 10"

check_value 15
if [ $? -eq 0 ]; then
  echo "Value is greater than 10."
else
  echo "Value is not greater than 10."
fi

echo "Test below 10"

check_value 9
if [ $? -eq 0 ]; then
  echo "Value is greater than 10."
else
  echo "Value is not greater than 10."
fi