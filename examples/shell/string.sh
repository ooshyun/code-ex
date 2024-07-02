#!/bin/bash
set -e

# # Method 2
# function run_command() {
#     command=""
#     for arg in "$@"
#     do
#         command="$command $arg"
#     done
#     echo "Executing command: $command"
#     tmp="tmp_script_$RANDOM.sh"
#     echo "$command" > $tmp
#     bash $tmp
#     rm -rf $tmp
# }

# # Define the command as a string through adding a string
# a="sudo /bin/date"
# b=" > ./test.log"

# echo "add '$a' + '$b' "
# command_string="$a$b"
# run_command $command_string


# a+=$b
# echo "added $a"


# x="abc \
# def"
# echo "nextline test $x"

# function test_nextline_in_func() {
#     y="xyz \
# abc"
#     echo "nextline test $y"
# }
# test_nextline_in_func
# # # Method 1
# # # Print the command to verify it
# # echo "Executing command: $command_string"
# # # Create a temporary script file
# # # If using 'eval', it can but not recommended
# # # The reason to not execute directly such as $command_string 
# # # is '>'.
# # echo "$command_string" > tmp_script.sh 

# # # Execute the temporary script
# # bash tmp_script.sh

# # # Clean up the temporary script
# # rm tmp_script.sh

# cat ./test.log
# rm -rf ./test.log


# string_sub="abcdefg"
# echo "string_sub: $string_sub"
# echo "string_sub[0:3]: ${string_sub:0:3}"
# echo "string_sub[0:-2]: ${string_sub:0:-2}"



# test="set-option"
# ls_test=$(ls -al $test)
# echo "ls_test: $ls_test"


# test="abcd \
#       efgh"

# echo "test: $test" 



# x="abc"
# y="${x%?}"
# z="${x:0:-2}"
# echo "x: $x"
# echo "y: $y"
# echo "z: $z"


# x_list=("a" "b" "c" "d")
# echo "x_list: ${x_list[@]}"
# x_list_string="${x_list[@]}"
# echo "x_list_string: $x_list_string"

x="a.b.c"
echo "x: $x"

# first character
echo "x_0: ${x:0:1}"
echo "x_1: ${x:2:1}"
echo "x_0: ${x:4:1}"