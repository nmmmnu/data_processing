#include "main_printhelp.h"
#include "main_istream.h"

#include "defs.h"

#include "main_user_collectors.h"

#include "collect_counter_all.h"

int main(int argc, char **argv){
	if (argc < 2)
		return printHelp(argv[0]);


	CollectUserTags		ut = {	"USER_TOP_TAGS",	TOP_COUNT			};
	CollectUserCountry	uc  = {	"USER_TOP_COUNTRY",	TOP_COUNT			};

	CollectUserLikes	tl = {	"TOTAL_LIKES",		TOP_COUNT,	"TOTAL"		};
	CollectUserComments	tc = {	"TOTAL_COMMENTS",	TOP_COUNT,	"TOTAL"		};
	CollectUserMedia	tm = {	"TOTAL_MEDIA",		TOP_COUNT,	"TOTAL"		};
	CollectCounterAll	tu = {	"TOTAL_USERS",				"TOTAL"		};

	std::vector<ICollect *> collectors = { 	&uc, &ut, &tl, &tc, &tm, &tu };



	ProcessorUser p = { constructStream(argv[1]), collectors };

	p.process();
	p.print();

	return 0;
}

