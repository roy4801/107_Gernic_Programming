#!/bin/bash

# Plot Alternative

pushd result/Alternative/ > /dev/null
echo Ploting Alternative
gnuplot plot_len.gp
gnuplot plot_line.gp
popd > /dev/null

# Plot Iterator
pushd result/Iterator/ > /dev/null
echo Ploting Iterator
gnuplot plot_len.gp
gnuplot plot_line.gp
popd > /dev/null

# Plot Simple
pushd result/Simple/ > /dev/null
echo Ploting Simple
gnuplot plot_len.gp
gnuplot plot_line.gp
popd > /dev/null

# sort compare
pushd result/ > /dev/null
echo Ploting sort
gnuplot sort_compare_len.gp
popd > /dev/null

pushd result/ > /dev/null
echo Ploting sort
gnuplot sort_compare_line.gp
popd > /dev/null

# input compare
pushd result/ > /dev/null
echo Ploting input
gnuplot input_compare_len.gp
popd > /dev/null

pushd result/ > /dev/null
echo Ploting input
gnuplot input_compare_line.gp
popd > /dev/null


# output compare
pushd result/ > /dev/null
echo Ploting output
gnuplot output_compare_len.gp
popd > /dev/null

pushd result/ > /dev/null
echo Ploting output
gnuplot output_compare_line.gp
popd > /dev/null