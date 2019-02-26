#!/bin/bash

function nl()
{
	echo >> out.txt
}

# echo Generating testcases...
# python3 ../testcase.py $1 $2
# echo Completed.

# C++ gen testcase
echo Compiling gen_test ...
g++ -Wall -std=c++11 -I.. gen_test.cpp -o gen_test
if [[ "$?" == "0" ]]; then
	echo Completed.
fi

# main
echo Compiling main ...
g++ -Wall -std=c++11 -I.. main.cpp -o main
if [[ "$?" == "0" ]]; then
	echo Completed.
fi

rm -f out.txt > /dev/null

for (( i=100; i <= 1000000; i *= 10)); do
	echo Testing 100 $i...
	./gen_test 100 $i
	echo 100 $i >> out.txt
	./main < testcase.txt >> out.txt
	nl; nl
	echo Completed.
done

for (( i=100; i <= 1000000; i *= 10)); do
	echo Testing $i 100...
	./gen_test $i 100
	echo $i 100 >> out.txt
	./main < testcase.txt >> out.txt
	nl; nl
	echo Completed.
done