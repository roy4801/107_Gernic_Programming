CXX = g++
CFLAGS = -Wall -std=c++11
INCLUDE = -I.
LIBS =

.PHONY:clean alternative iterator simple

all : plot

plot: alternative iterator simple
	cp Alternative/gnu.txt result/Alternative/data.txt
	cp Iterator/gnu.txt result/Iterator/data.txt
	cp Simple/gnu.txt result/Simple/data.txt
	# Plot Alternative
	pushd Alternative/ > /dev/null
	gnuplot plot.gp
	popd > /dev/null
	# Plot Iterator
	pushd Iterator/ > /dev/null
	gnuplot plot.gp
	popd > /dev/null
	# Plot Simple
	pushd Simple/ > /dev/null
	gnuplot plot.gp
	popd > /dev/null

alternative:
	${CXX} ${CFLAGS} ${INCLUDE} ${LIBS} Alternative/main.cpp -o Alternative/main
	./gen.sh Alternative

iterator:
	${CXX} ${CFLAGS} ${INCLUDE} ${LIBS} Iterator/main.cpp -o Iterator/main
	./gen.sh Iterator

simple:
	${CXX} ${CFLAGS} ${INCLUDE} ${LIBS} Simple/main.cpp -o Simple/main
	./gen.sh Simple

clean:
	rm -f Alternative/main Alternative/gen_test
	rm -f Iterator/main Iterator/gen_test
	rm -f Simple/main Simple/gen_test
	rm -f Iterator/*.exe Alternative/*.exe Simple/*.exe
	rm -f Iterator/*.txt Alternative/*.txt Simple/*.txt
	rm -f result/Iterator/*.png result/Alternative/*.png result/Simple/*.png
	rm -f result/Iterator/*.txt result/Alternative/*.txt result/Simple/*.txt
