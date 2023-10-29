#!bin/bash
set -e
NEWLINE=$'\n'

echo "$NEWLINE Case 1"
ls -l temp_$RANDOM || echo "Finished!"

echo "$NEWLINE Case 2"
ls -l || echo "Finished!"

echo "$NEWLINE Case 3"
ls -l temp_$RANDOM || set +e


echo "$NEWLINE Case 4"
raise_error() {
    set +e
    echo "Error!"
    set -e
}
ls -l temp_$RANDOM || raise_error
# ls -l temp_$RANDOM # it raise error

error_func_2() {
    ls -l temp_$RANDOM
}

error_func_1() {
    error_func_2
}

echo "$NEWLINE Case 5"
error_func_1 || raise_error


echo "End line!"