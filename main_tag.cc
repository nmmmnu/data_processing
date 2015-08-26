#include "main_printhelp.h"
#include "main_istream.h"

#include "defs.h"

#include "main_tag_collectors.h"

#include "collect_counter_all.h"

int main(int argc, char **argv){
	if (argc < 2)
		return printHelp(argv[0]);



	CollectTagCountry	cc1 = { "TOP_TAG_BY_COUNTRY",	TOP_COUNT	};
	CollectTagCity		cc2 = { "TOP_TAG_BY_CITY",	TOP_COUNT	};

	CollectTagTotal		ctt = { "TOP_TAG_TOTAL", 	TOP_COUNT,	"TOTAL"	};

	CollectCounterAll	cta = { "TOTAL_TAGS",				"TOTAL"	};

	std::vector<ICollect *> collectors = { &cc1, &cc2, &ctt, &cta };



	ProcessorTag p = { constructStream(argv[1]), collectors };

	p.process();
	p.print();

	return 0;
}
