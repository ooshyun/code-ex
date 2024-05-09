#!/bin/bash

touch $(pwd)/test.txt
mv $(pwd)/test.txt \
   $(pwd)/test2.txt

rm $(pwd)/test2.txt

if [ -d $(pwd)/tmp-test ]; then
    echo "$(pwd)/tmp-test folder exists."
    rm -r tmp-test
else 
    echo "$(pwd)/tmp-test folder does not exist."
fi
mkdir -p tmp-test/test1/test11 tmp-test/test2
tree tmp-test

rm -r tmp-test