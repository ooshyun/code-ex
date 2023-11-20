#!/bin/bash
# if shell do not use source, it make new bash scipt and apply it. 
# So, current shell we run shell script did not change such as cd
# But, if you check using cwd, the change is applied while shell is running

current_path=$(pwd)
nextline=$'\n'
temp_path="$current_path/tmp_$RANDOM"
temp_folder_path="$current_path/tmp_$RANDOM"
mkdir $temp_path

# Define a function to run command
function source_run_command() {
    command=""
    for arg in "$@"
    do
        command="$command $arg"
    done
    # echo "Executing command: $command"
    tmp="$temp_path/tmp_script_$RANDOM.sh"
    echo "#!/bin/bash$nextline$command" > $tmp
    source $tmp
    rm -rf $tmp
    # echo "Remove $tmp"
}


cd ..
echo "current dir: $(pwd)"
cd $current_path
echo "current dir: $(pwd)"

echo "-------------"

source_run_command cd ..
echo "current dir: $(pwd)"
source_run_command cd $current_path
echo "current dir: $(pwd)"


echo "-------------"
mkdir $temp_folder_path
source_run_command cd $temp_folder_path
echo "current dir: $(pwd)"
echo "current dir: $(pwd)" > test.log
cat ./test.log
source_run_command cd ..
echo "current dir: $(pwd)"
rm -rf $temp_folder_path

echo "-------------"

source_run_command cd test
echo "current dir: $(pwd)"
echo "current dir: $(pwd)" > test.log
cat ./test.log
source_run_command cd ..
echo "current dir: $(pwd)"

echo "-------------"

rmdir $temp_path