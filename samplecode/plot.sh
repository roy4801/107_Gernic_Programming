#!/bin/bash

# Plot Alternative
pushd result/Alternative/
gnuplot plot_len.gp
gnuplot plot_line.gp
popd

# Plot Iterator
pushd result/Iterator/
gnuplot plot_len.gp
gnuplot plot_line.gp
popd

# Plot Simple
pushd result/Simple/
gnuplot plot_len.gp
gnuplot plot_line.gp
popd