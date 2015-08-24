MYCC	= g++

OPTIM	= -O9

CC	= $(MYCC) -std=c++11 -Wall $(OPTIM)	\
		-MMD -MP			\
		-c

LINK	= $(MYCC) -o
LIBS	= -lstdc++

all:	processor_tag

clean:
	rm -f *.o *.d process

processor_tag: main_tag.o processor.o tsv.o	\
			collect_tag_country.o collect_tag_city.o collect_tag_total.o
	$(LINK) processor_tag			\
		main_tag.o processor.o tsv.o	\
			collect_tag_country.o collect_tag_city.o collect_tag_total.o	\
				$(LIBS)

%.o: %.cc
	$(CC) $<

-include $(SRC:%.cc=%.d)

