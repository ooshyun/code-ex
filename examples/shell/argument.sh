#!bin/bash
# how to get argument in shell script
echo $#   # 입력된 인자 값
echo $0   # 쉘스크립트 파일 실행 명령어

directory=$(dirname "$0")
echo "directory: $directory"

echo $1   # 첫 번째 인자 값
echo $2   # 두 번째 인자 값
echo $3   # 세 번째 인자 값
echo $4   # 네 번째 인자 값

echo $(cat $1)

if [ $1 = "1" ]
then
    echo "String!"
elif [ $1 -eq 1 ]
then
    echo "Number!"
fi

test_argument_empty() {
  local _x=""
  if [ -n "$1" ]; then
    _x=$1
  else
    _x="Nope!"
  fi
  echo $_x
}

test_argument_empty "Hello"
test_argument_empty
