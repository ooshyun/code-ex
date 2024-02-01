#!/bin/bash

# # Initialize variables
# filename=""
# verbose=0

# # Option strings
# # The colon after a letter indicates that the option requires an argument
# optstring="o:f:v:file"

# while getopts ${optstring} option; do
#   case ${option} in
#     o) object=${OPTARG} ;;
#     f) filename=${OPTARG} ;;
#     file) filename=${OPTARG} ;;
#     v) verbose=1 ;;
#     \?) echo "Usage: cmd [-v] [-o objectname] [-f filename]" ;;
#   esac
# done

# echo "Object: $object"
# echo "Filename: $filename"
# echo "Verbose: $verbose"

################################################

files=()
objects=()
verbose=0
name="default"

function add_to_array() {
    local array_name=$1
    local count=0

    while [[ "$#" -gt 1 && "$2" != "-"* ]]; do
        eval "$array_name+=(\"\$2\")" # Dynamically add to array
        shift
        ((count++))
    done
    echo $count
}

# Option parsing
while [[ "$#" -gt 0 && "$1" == "-"* ]]; do
    echo $1
    case $1 in
        -f|--file) 
            while [[ "$#" -gt 1 && "$2" != "-"* ]]; do
                files+=("$2") # Add to array
                shift
            done
            ;;
        -fn|--file-name) 
            while [[ "$#" -gt 1 && "$2" != "-"* ]]; do
                files+=("$2") # Add to array
                shift
            done
            ;;
        -v|--verbose) verbose=1 ;;
        -o|--object) 
            while [[ "$#" -gt 1 && "$2" != "-"* ]]; do
                objects+=("$2") # Add to array
                shift
            done
            ;;
        --name)
            # while [[ "$#" -gt 1 && "$2" != "-"* ]]; do
            #     name+="$2" # Add to array
            #     shift
            # done
            echo "Name: $2, all argu $@"
            count=$(add_to_array name "$@")
            echo $name
            shift $count
            ;;
        *) 
            echo "Unknown option: $1"
            exit 1
            ;;
    esac
    shift
done

# After option parsing, "$@" contains only positional arguments
positional_args=("$@")

echo "Verbose: $verbose"
echo "Files: ${files[@]}"
echo "Objects: ${objects[@]}"
echo "Positional arguments: ${positional_args[@]}"
echo "Name: $name"

if [ $verbose -eq 1 ]; then
    echo "Verbose mode enabled"
fi

################################################
