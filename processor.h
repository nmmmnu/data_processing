#ifndef _PROCESSOR_H
#define _PROCESSOR_H

#include "collect.h"

#include <string>
#include <vector>

// ==========================================

class Processor{
public:
	Processor(std::string filename, std::vector<ICollect *> collectors) :
				_filename(std::move(filename)),
				_collectors(collectors){}

public:
	void process();
	void processFile(std::istream & input);

private:
	std::string _filename;
	std::vector<ICollect *> _collectors;
};

#endif

