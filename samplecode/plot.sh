#!/bin/bash

# Plot Alternative
pushd result/Alternative/
gnuplot plot.gp
popd

# Plot Iterator
pushd result/Iterator/
gnuplot plot.gp
popd

# Plot Simple
pushd result/Simple/
gnuplot plot.gp
popd