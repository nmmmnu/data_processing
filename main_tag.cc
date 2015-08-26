#include "printhelp.h"

#include "defs.h"
#include "processor.h"

#include "main_tag_collectors.h"

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


	CollectTagCountry	cc1 = { "TOP_TAG_BY_COUNTRY",	TOP_COUNT	};
	CollectTagCity		cc2 = { "TOP_TAG_BY_CITY",	TOP_COUNT	};

	CollectTagTotal		ctt = { "TOP_TAG_TOTAL", 	TOP_COUNT,	"TOTAL"	};

	CollectCounterAll	cta = { "TOTAL_TAGS",				"TOTAL"	};

	std::vector<ICollect *> collectors = { &cc1, &cc2, &ctt, &cta };


	Processor p = { constructStream(argv[1]), collectors, TSV::POS_TAG };

	p.process();
	p.print();

	return 0;
}
