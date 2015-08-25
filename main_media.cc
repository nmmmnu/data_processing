#include "printhelp.h"

#include "defs.h"
#include "processor.h"

#include "collect_media_like.h"
#include "collect_media_comment.h"

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

	CollectMediaLike	c1 = { "TOP_MEDIA_BY_LIKE",	"TOTAL",	TOP_COUNT	};
	CollectMediaComment	c2 = { "TOP_MEDIA_BY_COMMENT",	"TOTAL",	TOP_COUNT	};

	std::vector<ICollect *> collectors = {
					//&c1,
					&c2 };


	Processor p = { constructStream(argv[1]), collectors, TSV::POS_MEDIA };

	p.process();
	p.print();

	return 0;
}

