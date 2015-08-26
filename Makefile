MYCC	= g++

OPTIM	= -O9

CC	= $(MYCC) -std=c++11 -Wall $(OPTIM)	\
		-MMD -MP			\
		-c

LINK	= $(MYCC) -o
LIBS	= -lstdc++

SRC	= $(wildcard *.cc)

TARGETS	=			\
	processor_tag		\
	processor_media

all:	$(TARGETS)

clean:
	rm -f *.o *.d		\
			$(TARGETS)

processor_tag: main_tag.o printhelp.o processor.o tsv.o		\
						collect_aggregate.o collect_counter_all.o
	$(LINK) $@ $^		$(LIBS)


processor_media: main_media.o printhelp.o processor.o tsv.o	\
						collect_aggregate.o collect_counter_all.o collect_counter.o
	$(LINK) $@ $^		$(LIBS)


%.o: %.cc
	$(CC) $<

-include $(SRC:%.cc=%.d)

