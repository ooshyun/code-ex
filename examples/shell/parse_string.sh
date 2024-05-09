#!/bin/sh

# 1.1 line parsing

a="my name is ohhh sh"

# Save the old IFS value so we can restore it later
OLD_IFS="$IFS"

# Set IFS to space to split the string into words
IFS=' '

# Use 'set' to positionally set the shell arguments ($1, $2, ...) to the words in the string
set -- $a

# Now you can access individual 'words' as positional parameters
echo "First word: $1"  # Output: my
echo "Second word: $2" # Output: name

# To print all 'words', loop over the positional parameters
echo "The string has $# words"
echo "All words and index:"
index=1
for word in "$@"; do
    echo "$index: $word"
    ((index++))
done

# Restore the original IFS value
IFS="$OLD_IFS"


# 1.2 more than 1 line
# a="my name is\nohhh sh"
a=$(ls -al *.txt)


# Input string with two lines
printf "%s\n" "$a" | while IFS= read -r line # Read each line
do
    # Save old IFS and set new one to split words in line
    OLD_IFS="$IFS"
    IFS=' '
    
    # Use set to assign words to positional parameters
    set -- $line
    
    # Now $1, $2, ... contain the words of the current line
    echo "Processing line: $line"
    for word in "$@"; do
        echo "  Word: $word"
    done
    
    # Restore original IFS
    IFS="$OLD_IFS"
done

# # 2. memory parsing
# # Specify the PID
# PID=750689

# # Check if the smaps file exists for the given PID
# if [ ! -f /proc/$PID/smaps ]; then
#     echo "smaps file for PID $PID does not exist."
#     exit 1
# fi

# # Initialize Pss sum variable
# PssSum=0

# # Extract Pss values, sum them up
# while read -r pss_value; do
#     # Remove the trailing "kB" and sum
#     PssSum=$((PssSum + pss_value))
# done <<EOF
# $(grep Pss: /proc/$PID/smaps | cut -d':' -f2 | cut -d'k' -f1)
# EOF


# # Initialize Pss sum variable
# PssSum=0

# temp_file=$(mktemp)
# echo "Temp file: $temp_file"
# grep Pss: /proc/$PID/smaps | cut -d':' -f2 | cut -d'k' -f1 | {
#     while IFS= read -r pss_value; do
#         # Remove the trailing "kB" and sum
#         echo $PssSum $pss_value
#         PssSum=$((PssSum + pss_value))
#     done
#     echo "Total Pss: $PssSum kB"
#     echo $PssSum > "$temp_file"
# }

# # Read the sum from the temporary file back into PssSum in the parent shell
# PssSum=$(cat "$temp_file")
# echo "Total Pss: $PssSum kB"

# # Cleanup the temporary file
# rm "$temp_file"

# # 3. pgrep, sh test.sh pattern
# # Check if a pattern was provided
# if [ "$#" -ne 1 ]; then
#     echo "Usage: $0 <pattern>"
#     exit 1
# fi

# pattern="$1"

# # List all processes, filter by pattern, exclude grep command
# # Then, use a while loop to read each line and extract the PID
# ps | grep "$pattern" | grep -v grep | grep -v sh | while IFS= read -r line; do
#     # Depending on your system, adjust the cut field (-f) as needed
#     echo "$line"
#     echo "$line" | cut -d' ' -f1
# done


# # 4. pid parse
# #!/bin/sh
# pid=74356
# n_cpu_usage=30
# while [ $n_cpu_usage -gt 0 ]; do
#   temp=$(pidstat -p $pid 1 1 | sed -n '$p')
#   echo "cpu_usage: $temp"

#   cpu_usage_irix=$(echo "$temp" | tr -s ' ' | cut -d' ' -f8)
#   echo "cpu_usage_irix: $cpu_usage_irix"

#   cpu_usage=$(echo $cpu_usage_irix)
#   current_time=$(date +"%Y-%m-%d %H:%M:%S")
#   echo "$current_time : $cpu_usage %"

#   n_cpu_usage=$((n_cpu_usage - 1))
# done



# 5. parse string
index=0
while IFS=" " read -r line; do
    if [ -z "$line" ]; then
        break
    fi
    echo "$index $line"



    index=$((index+1))

done < "tmp.parse"


pid_path="tmp2.parse"

cleanup() {
  echo "Caught Ctrl+C, stopping the script."
  pid_list=""  
  # Perform any cleanup tasks here
  while IFS=" " read -r line; do
    if [ -z "$line" ]; then
      break
    fi
    echo $line
    
    iword=0
    for word in $line; do
      echo "word: $iword $word"
      if [ $iword -eq 2 ]; then
        pid_list+="$word "
        break
      fi
      iword=$((iword+1))
    done
  done < $pid_path
  # Exit the script
  echo "Killing $pid_list"
  # kill -9 $pid_list
#   rm -rf $pid_path
#   exit 0
}

cleanup