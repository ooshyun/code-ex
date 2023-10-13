#!/bin/bash

# Define a function to be executed in parallel
task1() {
    echo "Task 1 started"
    sleep 3
    echo "Task 1 completed"
}

task2() {
    echo "Task 2 started"
    sleep 5
    echo "Task 2 completed"
}

# Execute functions in parallel
task1 &
task2 &

# Wait for both tasks to finish
wait

echo "All tasks completed"