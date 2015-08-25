#include "printhelp.h"

#include "defs.h"
#include "processor.h"

#include "main_media_collectors.h"

#include "collect_counter_all.h"

#include <iostream>
#include <fstream>

std::ifstream	ifs;

static std::istream & constructStream(const char *filename){
	if (filename[0] == '-' && filename[1] == '\0')
		return std::cin;

	ifs.open(filename);

	return ifs;
}



int main(int argc, char **argv){
	if (argc < 2)
		return printHelp(argv[0]);

	CollectMediaLike		lc1 = { "TOP_MEDIA_BY_LIKES",		"TOTAL",	TOP_COUNT	};
	CollectMediaLikeCountry		lc2 = { "TOP_MEDIA_BY_LIKE_COUNTRY",			TOP_COUNT	};

	CollectMediaComment		cc1 = { "TOP_MEDIA_BY_COMMENTS",	"TOTAL",	TOP_COUNT	};
	CollectMediaCommentCountry	cc2 = { "TOP_MEDIA_BY_COMMENT_COUNTRY",			TOP_COUNT	};

	CollectCounterAll		tc3 = { "TOP_MEDIA_ALL",		"TOTAL"				};

	std::vector<ICollect *> collectors = { &lc1, &lc2, &cc1, &cc2, &tc3 };


	Processor p = { constructStream(argv[1]), collectors, TSV::POS_MEDIA };

	p.process();
	p.print();

	return 0;
}

