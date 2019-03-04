CXX = g++
CFLAGS = -Wall -std=c++11
INCLUDE = -I.
LIBS =

.PHONY:clean alternative iterator simple

all : alternative iterator simple plot

plot: Alternative/gnu.txt Iterator/gnu.txt Simple/gnu.txt
	cp Alternative/gnu_len.txt result/Alternative/data_len.txt
	cp Iterator/gnu_len.txt result/Iterator/data_len.txt
	cp Simple/gnu_len.txt result/Simple/data_len.txt
	cp Alternative/gnu_line.txt result/Alternative/data_line.txt
	cp Iterator/gnu_line.txt result/Iterator/data_line.txt
	cp Simple/gnu_line.txt result/Simple/data_line.txt
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