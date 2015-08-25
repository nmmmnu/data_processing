MYCC	= g++

OPTIM	= -O9

CC	= $(MYCC) -std=c++11 -Wall $(OPTIM)	\
		-MMD -MP			\
		-c

LINK	= $(MYCC) -o
LIBS	= -lstdc++

TARGETS	=			\
	processor_tag		\
	processor_media

all:	$(TARGETS)

clean:
	rm -f *.o *.d		\
			$(TARGETS)

processor_tag: main_tag.o printhelp.o processor.o tsv.o	\
			collect_tag_country.o collect_tag_city.o collect_tag_total.o
	$(LINK) $@ $^		$(LIBS)


processor_media: main_media.o printhelp.o processor.o tsv.o	\
			collect_media_like.o collect_media_like_country.o	\
			collect_media_comment.o 				\
			collect_media_total.o
	$(LINK) $@ $^		$(LIBS)


%.o: %.cc
	$(CC) $<

-include $(SRC:%.cc=%.d)

