MYCC	= g++

OPTIM	= -O9

CC	= $(MYCC) -std=c++14 -Wall $(OPTIM)	\
		-c

LINK	= $(MYCC) -o
LIBS	= -lstdc++

all:	process


clean:
	rm -f *.o *.d process

process: process.o
	$(LINK) process		process.o		$(LIBS)

process.o: process.cc
	$(CC) process.cc

