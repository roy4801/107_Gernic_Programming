#!/bin/bash


Color_Off='\033[0m'
COLOR_GREEN='\e[0;32m'
COLOR_RED='\e[0;31m'

# check the C-code need to switch mode

function reset-nl()
{
	echo > result.txt
	echo "result:" > result.txt
}

function nl()
{
	echo "Testing len : ${M[$len]} line:${N[$line]}"
	./gen_test ${M[$len]} ${N[$line]}
	echo "len:${M[$len]} line:${N[$line]}" >> result.txt
	./main < testcase.txt >> result.txt
	echo -e "${COLOR_GREEN}Completed.${Color_Off}"
	echo >> result.txt
}

function nl_gnu()
{
	echo "Testing len : ${M[$len]} line:${N[$line]}"
	echo -n $alpht | awk '{printf("%c",$1)}'  >> gnu.txt
	echo -n " " >> gnu.txt
	((alpht++))
	./gen_test ${M[$len]} ${N[$line]}
	./main < testcase.txt >> gnu.txt
	echo >> gnu.txt
	echo -e "${COLOR_GREEN}Completed.${Color_Off}"
	# echo >> gnu.txt
}

function reset-nl_gnu()
{
	echo -n "" > gnu.txt
}


pushd $1


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

reset-nl_gnu;
# reset-nl;

N=("1000" "5000" "10000" "50000" "100000")
M=("100", "500", "1000")
alpht=65

for line in 0 1 2 3 4
do
	for len in 0 1 2
		do

			# general
			# nl;

			# gnu-testcase
			nl_gnu;
		done
done

popd $1
