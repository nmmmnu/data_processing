MYCC	= g++

OPTIM	= -O9

CC	= $(MYCC) -std=c++11 -Wall $(OPTIM)	\
		-c

LINK	= $(MYCC) -o
LIBS	= -lstdc++

all:	process



clean:
	rm -f *.o *.d process



process: main.o processor.o tsv.o
	$(LINK) process		main.o processor.o tsv.o	$(LIBS)



main.o: main.cc defs.h
	$(CC) main.cc

tsv.o: tsv.cc
	$(CC) tsv.cc

processor.o: processor.cc processor.h defs.h tag.h tsv.h
	$(CC) processor.cc

