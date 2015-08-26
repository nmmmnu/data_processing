#ifndef _PROCESSOR_H
#define _PROCESSOR_H

#include "collect.h"

#include <istream>

#include <string>
#include <vector>

// ==========================================

class Processor{
public:
	Processor(std::istream & input, const std::vector<ICollect *> &collectors) :
				_input(input),
				_collectors(collectors){}

public:
	void process();
	void print() const;

private:
	virtual const std::string &getField(TSV &fields) const = 0;

private:
	void _aggregate(const TSV & fields, const std::string & fld);
	void _store(const std::string & fld);

private:
	std::istream			&_input;
	const std::vector<ICollect *>	&_collectors;
};

#endif

