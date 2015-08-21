MYCC	= g++

OPTIM	= -O9

CC	= $(MYCC) -std=c++11 -Wall $(OPTIM)	\
		-c

LINK	= $(MYCC) -o
LIBS	= -lstdc++

all:	process



clean:
	rm -f *.o *.d process



process: main.o processor.o tsv.o collectcountry.o collectcountrycity.o
	$(LINK) process		\
		main.o processor.o tsv.o collectcountry.o collectcountrycity.o	\
			$(LIBS)



main.o: main.cc defs.h collect.h tag.h tsv.h
	$(CC) main.cc

tsv.o: tsv.cc
	$(CC) tsv.cc

processor.o: processor.cc processor.h collect.h tag.h tsv.h
	$(CC) processor.cc

collectcountry.o: collectcountry.cc collectcountry.h collect.h tsv.h tag.h
	$(CC) collectcountry.cc

collectcountrycity.o: collectcountrycity.cc collectcountrycity.h collect.h tsv.h tag.h
	$(CC) collectcountrycity.cc

