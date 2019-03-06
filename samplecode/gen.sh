#!/bin/bash

COLOR_OFF=$'\033[0m'
COLOR_GREEN=$'\e[0;32m'
COLOR_RED=$'\e[0;31m'


# check the C-code need to switch mode

function info()
{
	echo -e "${COLOR_GREEN}$1${COLOR_OFF}"
}

function warn()
{
	echo -e "${COLOR_RED}$1${COLOR_OFF}"
}

# print func
# Usage: print <msg>
# It will replace "/rd/" with "${COLOR_RED}" and "/ge/" with "${COLOR_GREEN}"
function print()
{
	echo -e "$(echo $1 | sed -e "s/\/rd\//${COLOR_RED}/g" -e "s/\/ge\//${COLOR_GREEN}/g")${COLOR_OFF}"
}

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
	info "Completed."
	echo >> result.txt
}

function nl_gnu_len()
{
	echo "Testing len:${M[$len]} line:${N[$line]}"
	echo -n "\"(${M[$len]} ${N[$line]})\"" >> gnu_len.txt
	echo -n " " >> gnu_len.txt
	./gen_test ${M[$len]} ${N[$line]}
	./main len < testcase.txt
	echo >> gnu_len.txt
	info "Completed."
	# echo >> gnu.txt
}

function nl_gnu_line()
{
	echo "Testing len:${M[$len]} line:${N[$line]}"
	echo -n "\"(${M[$len]} ${N[$line]})\"" >> gnu_line.txt
	echo -n " " >> gnu_line.txt
	./gen_test ${M[$len]} ${N[$line]}
	./main line < testcase.txt
	echo >> gnu_line.txt
	info "Completed."
	# echo >> gnu.txt
}

function reset-nl_gnu()
{
	echo -n "" > gnu_line.txt
	echo -n "" > gnu_len.txt
}

pushd $1 > /dev/null

print "/rd/Compiling /ge/gen_test ..."
g++ -std=c++11 -I.. gen_test.cpp -o gen_test
if [[ "$?" == "0" ]]; then
	info "gen_test Completed."
fi

g++ -std=c++11 -I.. main.cpp -o main
if [[ "$?" == "0" ]]; then
	info "main Completed."
fi

sleep 1s

reset-nl_gnu;
# reset-nl;

N=("1000" "5000" "10000" "50000" "100000" "500000")
M=("100" "500" "1000")

# keep the len
for len in `seq 0 2`;
do
	for line in `seq 0 5`;
		do

			# general
			# nl;

			# gnu-testcase
			nl_gnu_len;
		done
done


# keep the line
for line in `seq 0 5`;
do
	for len in `seq 0 2`;
		do

			# general
			# nl;

			# gnu-testcase
			nl_gnu_line;
		done
done

popd
