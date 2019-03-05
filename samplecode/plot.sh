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