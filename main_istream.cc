#include "main_istream.h"

#include <iostream>

std::ifstream	ifs;

std::istream &constructStream(const char *filename){
	if (filename[0] == '-' && filename[1] == '\0')
		return std::cin;

	ifs.open(filename);

	return ifs;
}

