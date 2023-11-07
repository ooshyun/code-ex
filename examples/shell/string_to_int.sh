#!bin/bash
a=1
b=2

echo " define like int a is"
if [ $a = "1" ]
then
    echo "String!"
fi

if [ $a -eq 1 ]
then
    echo "Number!"
fi

a="1"
b="2"

echo " define string a is"

if [ $a = "1" ]
then
    echo "String!" 
fi

if [ $a -eq 1 ]
then
    echo "Number!"
fi

c=$(($a+$b))
d=$(expr $a + $b)

echo " c is"
if [ $c = "3" ]
then
    echo "String!"
fi

if [ $c -eq 3 ]
then
    echo "Number!"
fi

echo " d is"

if [ $d = "3" ]
then
    echo "String!"
fi

if [ $d -eq 3 ]
then
    echo "Number!"
fi