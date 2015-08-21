MYCC	= g++

OPTIM	= -O9

CC	= $(MYCC) -std=c++11 -Wall $(OPTIM)	\
		-c

LINK	= $(MYCC) -o
LIBS	= -lstdc++

all:	process



clean:
	rm -f *.o *.d process



process: main.o processor.o tsv.o	\
			collect_tag_country.o collect_tag_city.o collect_tag_total.o
	$(LINK) process				\
		main.o processor.o tsv.o	\
			collect_tag_country.o collect_tag_city.o collect_tag_total.o	\
				$(LIBS)



main.o: main.cc defs.h collect.h tag.h tsv.h	\
			collect_tag_country.h collect_tag_city.h collect_tag_total.h
	$(CC) main.cc

tsv.o: tsv.cc
	$(CC) tsv.cc

processor.o: processor.cc processor.h collect.h tag.h tsv.h
	$(CC) processor.cc

collect_tag_country.o: collect_tag_country.cc collect_tag_country.h collect.h tsv.h tag.h
	$(CC) collect_tag_country.cc

collect_tag_city.o: collect_tag_city.cc collect_tag_city.h collect.h tsv.h tag.h
	$(CC) collect_tag_city.cc

collect_tag_total.o: collect_tag_total.cc collect_tag_total.h collect.h
	$(CC) collect_tag_total.cc


