CXX = g++
CFLAGS = -Wall -std=c++11
INCLUDE = -I.
LIBS =

.PHONY:clean clean_all clean_result alternative iterator simple

all : alternative iterator simple plot_data gen_total plot excel

plot_data: Alternative/gnu_len.txt Iterator/gnu_len.txt Simple/gnu_len.txt Alternative/gnu_line.txt Iterator/gnu_line.txt Simple/gnu_line.txt
	cp Alternative/gnu_len.txt result/Alternative/data_len.txt
	cp Iterator/gnu_len.txt result/Iterator/data_len.txt
	cp Simple/gnu_len.txt result/Simple/data_len.txt
	cp Alternative/gnu_line.txt result/Alternative/data_line.txt
	cp Iterator/gnu_line.txt result/Iterator/data_line.txt
	cp Simple/gnu_line.txt result/Simple/data_line.txt


gen_total:
	python3 gen_total.py

plot:
	./plot.sh

alternative:
	./gen.sh Alternative

iterator:
	./gen.sh Iterator

simple:
	./gen.sh Simple

excel: result/Alternative/data_len.txt result/Alternative/data_line.txt result/Iterator/data_len.txt result/Iterator/data_line.txt result/Simple/data_len.txt result/Simple/data_line.txt
	python3 gen_xlsx.py -i Alternative Iterator Simple -o result

clean:
	rm -f Alternative/main Alternative/gen_test
	rm -f Iterator/main Iterator/gen_test
	rm -f Simple/main Simple/gen_test
	rm -f Iterator/*.exe Alternative/*.exe Simple/*.exe
	rm -f Iterator/*.txt Alternative/*.txt Simple/*.txt

clean_result:
	rm -f result/Iterator/*.png result/Alternative/*.png result/Simple/*.png
	rm -f result/Iterator/*.txt result/Alternative/*.txt result/Simple/*.txt
	rm -f result/*.png

clean_all: clean clean_result
