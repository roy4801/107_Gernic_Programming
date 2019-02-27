#!/bin/bash

function nl()
{
	echo >> result.txt
}

# Reset
Color_Off='\033[0m'
COLOR_GREEN='\e[0;32m'
COLOR_RED='\e[0;31m'

echo -e "${COLOR_RED}Compiling ${COLOR_GREEN}gen_test ...${Color_Off}"

g++ -std=c++11 -I.. gen_test.cpp -o gen_test
if [[ "$?" == "0" ]]; then
	echo -e "${COLOR_GREEN}gen_test Completed.${Color_Off}"
fi

g++ -std=c++11 -I.. main.cpp -o main
if [[ "$?" == "0" ]]; then
	echo -e "${COLOR_GREEN}main Completed.${Color_Off}"
fi

sleep 1s
echo > result.txt

#testing
for ((i=100; i <= 1000000; i*=10)); do
	echo "Testing len:100 line:$i"
	./gen_test 100 $i
	echo "len:100 line:$i" >> result.txt
	./main < testcase.txt >> result.txt
	nl;
	echo -e "${COLOR_GREEN}Completed.${Color_Off}"
done

for ((i=100; i <= 1000000; i*=10)); do
	echo "Testing len:$i line:100"
	./gen_test $i 100
	echo "len:$i line:100" >> result.txt
	./main < testcase.txt >> result.txt
	nl;
	echo -e "${COLOR_GREEN}Completed.${Color_Off}"

done

