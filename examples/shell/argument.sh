#!bin/bash
# how to get argument in shell script
echo $#   # 입력된 인자 값
echo $0   # 쉘스크립트 파일 실행 명령어
echo $1   # 첫 번째 인자 값
echo $2   # 두 번째 인자 값
echo $3   # 세 번째 인자 값
echo $4   # 네 번째 인자 값


if [ $1 = "1" ]
then
    echo "String!"
elif [ $1 -eq 1 ]
then
    echo "Number!"
fi