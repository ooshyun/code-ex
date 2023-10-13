#!bin/bash

set -e

# Define the command as a string through adding a string
a="/bin/date"
b=" > ./test.log"

echo "add '$a' + '$b' "
command_string="$a$b"

# Print the command to verify it
echo "Executing command: $command_string"

# Create a temporary script file
# If using 'eval', it can but not recommended
# The reason to not execute directly such as $command_string 
# is '>'.
echo "$command_string" > tmp_script.sh 

# Execute the temporary script
bash tmp_script.sh

cat ./test.log
rm -rf ./test.log

# Clean up the temporary script
rm tmp_script.sh

