#!/bin/bash

# Define a function named "greet"
greet() {
    echo "Hello, $1 $2!"

    echo "argc: $#"
    for arg in "$@"
    do
        command="$command $arg"
    done
    echo "args: $command"
}

# Call the function with two arguments, one containing spaces
echo "  Case 1"
greet "Alice" "Smith Johnson"
echo "---------"


echo "  Case 2"
greet "ls -h > echo.txt" "Smith Johnson"
echo "---------"

greet_int () {
    echo "Hello, $1"
}

echo "  Case 3"
greet_int 3
echo "---------"


