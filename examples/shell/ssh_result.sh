#!/bin/bash


result=$(ssh docker.cochl.iptime.org "
            echo 0
            # exit 1
            echo 1 > /dev/null
            echo \$(pwd)
            echo "hello world"
        ")
echo $result