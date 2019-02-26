CXX = g++
CFLAGS = -Wall -std=c++11
INCLUDE = -I.
LIBS =

.PHONY:clean alternative iterator

all : alternative iterator

alternative:
	${CXX} ${CFLAGS} ${INCLUDE} ${LIBS} Alternative/main.cpp -o Alternative/Alternative

iterator:
	${CXX} ${CFLAGS} ${INCLUDE} ${LIBS} Iterator/main.cpp -o Iterator/Iterator

clean:
	rm -f Iterator/Iterator Alternative/Alternative