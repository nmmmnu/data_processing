#ifndef _PROCESSOR_H
#define _PROCESSOR_H

#include "collect.h"

#include <istream>

#include <string>
#include <vector>

// ==========================================

class Processor{
public:
	Processor(std::istream & input, const std::vector<ICollect *> &collectors, char const fieldID) :
				_input(input),
				_collectors(collectors),
				_fieldID(fieldID){}

public:
	void process();
	void print() const;

private:
	void _collect(const TSV & fields, const std::string & fld);
	void _store(const std::string & fld);

private:
	std::istream			&_input;
	const std::vector<ICollect *>	&_collectors;
	char				_fieldID;
};

#endif

