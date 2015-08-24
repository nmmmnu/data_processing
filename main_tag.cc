#include <cstdio>

#include "defs.h"
#include "processor.h"

#include "collect_tag_country.h"
#include "collect_tag_city.h"
#include "collect_tag_total.h"

#include <iostream>
#include <fstream>

static int printHelp(const char *name);



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


	CollectTagCountry	c1 = { "TOP_TAG_BY_COUNTRY",			TOP_COUNT, COUNTRY_RESERVE	};
	CollectTagCity		c2 = { "TOP_TAG_BY_CITY",			TOP_COUNT, CITY_RESERVE		};
	CollectTagTotal		c3 = { "TOP_TAG_TOTAL", 	"TOTAL",	TOP_COUNT			};

	std::vector<ICollect *> collectors = { &c1, &c2, &c3 };


	Processor p = { constructStream(argv[1]), collectors, TSV::POS_TAG };

	p.process();
	p.print();

	return 0;
}

// ============================================

static int printHelp(const char *name){
	constexpr static const auto format = "\t%s %-*s - %s\n";
	constexpr static const auto fpos1 = 11;
	constexpr static const auto fpos2 = 12;

	printf("%s version %s\n", name, VERSION);
	printf("\t%-*s: %u\n",		fpos1, "loop count",	TOP_COUNT);
	printf("\t%-*s: %s %s\n",	fpos1, "build",		__DATE__, __TIME__);

	printf("\n");

	printf("Usage\n");
	printf(format, name, fpos2, "[file]",		"Load data from file");
	printf(format, name, fpos2, "-",		"Load data from stdin, usually 10x sloooow :-)");
	printf(format, name, fpos2, "/dev/stdin",	"Load data from stdin (fast, UNIX only)");

	return 1;
}

