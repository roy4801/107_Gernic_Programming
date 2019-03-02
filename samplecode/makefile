CXX = g++
CFLAGS = -Wall -std=c++11
INCLUDE = -I.
LIBS =

.PHONY:clean alternative iterator simple

all : alternative iterator simple plot

plot: Alternative/gnu.txt Iterator/gnu.txt Simple/gnu.txt
	cp Alternative/gnu.txt result/Alternative/data.txt
	cp Iterator/gnu.txt result/Iterator/data.txt
	cp Simple/gnu.txt result/Simple/data.txt
	./plot.sh

alternative:
	./gen.sh Alternative

iterator:
	./gen.sh Iterator

simple:
	./gen.sh Simple

clean:
	rm -f Alternative/main Alternative/gen_test
	rm -f Iterator/main Iterator/gen_test
	rm -f Simple/main Simple/gen_test
	rm -f Iterator/*.exe Alternative/*.exe Simple/*.exe
	rm -f Iterator/*.txt Alternative/*.txt Simple/*.txt
	rm -f result/Iterator/*.png result/Alternative/*.png result/Simple/*.png
	rm -f result/Iterator/*.txt result/Alternative/*.txt result/Simple/*.txt
