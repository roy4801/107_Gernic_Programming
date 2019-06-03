#!/bin/bash

g++ -DDBG -std=c++11 main.cpp -o dijk
if [ "$?" == "0" ]; then
	echo Complete
	./dijk
fi

