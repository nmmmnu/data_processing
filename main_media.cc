#include "main_printhelp.h"
#include "main_istream.h"

#include "defs.h"

#include "main_media_collectors.h"

#include "collect_counter_all.h"

int main(int argc, char **argv){
	if (argc < 2)
		return printHelp(argv[0]);



	CollectMediaLike		lc1 = { "TOP_MEDIA_BY_LIKES",		TOP_COUNT,	"TOTAL"	};
	CollectMediaLikeCountry		lc2 = { "TOP_MEDIA_BY_LIKE_COUNTRY",	TOP_COUNT		};

	CollectMediaComment		cc1 = { "TOP_MEDIA_BY_COMMENTS",	TOP_COUNT,	"TOTAL"	};
	CollectMediaCommentCountry	cc2 = { "TOP_MEDIA_BY_COMMENT_COUNTRY",	TOP_COUNT		};

	CollectCounterAll		tca = { "TOP_MEDIA_ALL",		"TOTAL"			};

	std::vector<ICollect *> collectors = { &lc1, &lc2, &cc1, &cc2, &tca };



	ProcessorMedia p = { constructStream(argv[1]), collectors };

	p.process();
	p.print();

	return 0;
}

