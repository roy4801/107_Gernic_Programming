#!/bin/bash

pushd .. > /dev/null
make $1
popd > /dev/null

./Alternative < test.txt