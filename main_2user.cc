#include "main_printhelp.h"
#include "main_istream.h"

#include "defs.h"

#include "main_2user_collectors.h"

int main(int argc, char **argv){
	if (argc < 2)
		return printHelp(argv[0]);


	CollectUserAllTags	at = {	"USER_ALL_LIKES",	TOP_COUNT			};

	std::vector<ICollect *> collectors = {  &at };



	Processor2User p = { constructStream(argv[1]), collectors };

	p.process();
	p.print();

	return 0;
}

