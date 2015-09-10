#include "main_printhelp.h"
#include "main_istream.h"

#include "defs.h"

#include "main_user_collectors.h"

#include "collect_counter_all.h"

int main(int argc, char **argv){
	if (argc < 2)
		return printHelp(argv[0]);


	CollectUserTopTags	ut = {	"USER_TOP_TAGS",	TOP_COUNT			};
	CollectUserTopCountry	uc = {	"USER_TOP_COUNTRY",	TOP_COUNT			};

	CollectUserAllLikes	al = {	"USER_ALL_LIKES",	TOP_COUNT			};
	CollectUserAllComments	ac = {	"USER_ALL_COMMENTS",	TOP_COUNT			};
	CollectUserAllCountry	an = {	"USER_ALL_COUNTRY",	TOP_COUNT			};

	CollectUserLikes	tl = {	"TOTAL_LIKES",		TOP_COUNT,	"TOTAL"		};
	CollectUserComments	tc = {	"TOTAL_COMMENTS",	TOP_COUNT,	"TOTAL"		};
	CollectUserMedia	tm = {	"TOTAL_MEDIA",		TOP_COUNT,	"TOTAL"		};

	CollectUserRelLikes	rl = {	"AVG_LIKES",		TOP_COUNT,	"TOTAL"		};
	CollectUserRelComments	rc = {	"AVG_COMMENTS",		TOP_COUNT,	"TOTAL"		};

	CollectCounterAll	tu = {	"TOTAL_USERS",				"TOTAL"		};

	std::vector<ICollect *> collectors =
				{
					&ut, &uc,
					&al, &ac, &an,
					&tl, &tc, &tm,
					&rl, &rc,
					&tu
				};



	ProcessorUser p = { constructStream(argv[1]), collectors };

	p.process();
	p.print();

	return 0;
}

