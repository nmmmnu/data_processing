MYCC	= g++

OPTIM	= -O9

CC	= $(MYCC) -std=c++11 -Wall $(OPTIM)	\
		-MMD -MP			\
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

%.o: %.cc
	$(CC) $<

-include $(SRC:%.cc=%.d)

