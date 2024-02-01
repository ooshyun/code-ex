#!/bin/bash

# Function that "returns" a string
function get_string() {
    local my_string="Hello, world!"
    echo "$my_string"
}

# Call the function and capture the output
returned_string=$(get_string)

# Use the captured string
echo "The function returned: $returned_string"

# Function that modifies its argument
function modify_string() {
    local input_string=$1  # Get the first argument
    local modified_string="Modified: $input_string"
    echo "$modified_string"
}

# Original string
original_string="Hello, world!"

# Call the function and pass the string as an argument
modified_string=$(modify_string "$original_string")

# Display the modified string
echo "Original string: $original_string"
echo "Modified string: $modified_string"


# The original command
cmd="aarch64-linux-gnu-gcc -mcpu=cortex-a53 -march=armv8-a+crc+crypto -fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security --sysroot=/opt/axis/acapsdk/sysroots/aarch64 -L/opt/axis/acapsdk/sysroots/aarch64/usr/lib"

# Function to remove the --sysroot argument
remove_sysroot() {
    local command=$1
    echo "${command/--sysroot=[^ ]* /}"
}

# Remove --sysroot from the command
modified_cmd=$(remove_sysroot "$cmd")

# Display the modified command
echo "Original Command: $cmd"
echo "Modified Command: $modified_cmd"

# Function to remove an argument and its value
function remove_argument() {
    local command=$1
    local arg_to_remove=$2

    # Handle the case where the argument is at the end of the string
    command="${command%${arg_to_remove}=*}"

    # Handle the case where the argument is followed by other arguments
    command="${command/${arg_to_remove}=[^ ]* /}"

    echo "$command"
}

# Remove -mcpu argument and its value
cmd="aarch64-linux-gnu-gcc -mcpu=cortex-a53 -march=armv8-a+crc+crypto -fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security --sysroot=/opt/axis/acapsdk/sysroots/aarch64 -L/opt/axis/acapsdk/sysroots/aarch64/usr/lib"
modified_cmd=$(remove_argument "$cmd" "-mcpu")
echo "Command after removing -mcpu: $modified_cmd"

# Remove --sysroot argument and its value
cmd="aarch64-linux-gnu-gcc -mcpu=cortex-a53 -march=armv8-a+crc+crypto -fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security --sysroot=/opt/axis/acapsdk/sysroots/aarch64 -L/opt/axis/acapsdk/sysroots/aarch64/usr/lib"
modified_cmd=$(remove_argument "$cmd" "--sysroot")
echo "Command after removing --sysroot: $modified_cmd"



# Original command
cmd="aarch64-linux-gnu-gcc -mcpu=cortex-a53 -march=armv8-a+crc+crypto -fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security -L/opt/axis/acapsdk/sysroots/aarch64/usr/lib"

# Function to remove a specific argument
remove_argument() {
    local command=$1
    local arg_to_remove=$2

    # Remove the specific argument
    # Handles both the case where the argument is followed by others or at the end
    command="${command// $arg_to_remove / }"
    command="${command% $arg_to_remove}"

    echo "$command"
}

# Usage example:
cmd="aarch64-linux-gnu-gcc -mcpu=cortex-a53 -march=armv8-a+crc+crypto -fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security -L/opt/axis/acapsdk/sysroots/aarch64/usr/lib"
echo "Original command: $cmd"
# Remove -L/opt/axis/acapsdk/sysroots/aarch64/usr/lib argument
modified_cmd=$(remove_argument "$cmd" "-L/opt/axis/acapsdk/sysroots/aarch64/usr/lib")
echo "Command after removal: $modified_cmd"