#!/bin/bash

TARGET=140.136.150.68

# Remote debugging
if [ "$2" == "-g" ]; then
	ssh $TARGET mkdir /tmp/$1/
	pushd $1 > /dev/null
	echo Copying files...
	scp $1.cpp $TARGET:/tmp/$1/
	echo Compiling...
	ssh $TARGET g++ -g -std=c++14 /tmp/$1/$1.cpp -o /tmp/$1/$1.out
	echo Start remote debugging. Go to $TARGET:5000
	echo Waiting... \(\^C exit\)
	ssh $TARGET gdbgui -r /tmp/$1/$1.out
	echo Bye
	ssh $TARGET pkill gdbgui
	ssh $TARGET rm -rf /tmp/$1/
	popd > /dev/null
	exit
fi

g++ -std=c++14 $1/$1.cpp -o $1/$1.out
if [ "$?" == "0" ]; then
	./$1/$1.out
	rm -f ./$1/$1.out
fi
