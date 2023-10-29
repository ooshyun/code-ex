#!bin/bash

# > will overwrite to new file
# >> will append to the end of file

next_line=$'\n'
echo "Case 1" >> ./test.log
echo "Case 2" >> ./test.log
echo "Case 3$next_line Case 4" >> ./test.log
cat ./test.log
rm -rf ./test.log
