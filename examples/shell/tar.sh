#!bin/bash
path="/Users/seunghyunoh/workplace/examplace/practice/examples/shell"

mkdir -p test_tar/test_tar_child
cp ./*.sh test_tar/test_tar_child
cd ${path}/test_tar
tar -cvf test_tar_child.tar test_tar_child
mv test_tar_child.tar ${path}
cd ${path}

rm -rf ${path}/test_tar

