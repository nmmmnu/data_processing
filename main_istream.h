#ifndef _MAIN_ISTREAM_H
#define _MAIN_ISTREAM_H

#include <fstream>

extern std::ifstream ifs;

std::istream &constructStream(const char *filename);

#endif

