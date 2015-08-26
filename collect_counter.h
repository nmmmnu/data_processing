#ifndef _COLLECT_COUNTER_H
#define _COLLECT_COUNTER_H

#include "collect.h"

/*
This class have following responsibility:
========================================
It collects a number such a number of comments,
store it in the "rolling" set,
and keep up to _topCount rows.
*/

class ICollectCounter : public ICollectAggregate{
public:
	ICollectCounter(const std::string &prefix, unsigned const topCount, const std::string &name) :
				ICollectAggregate(prefix, topCount, OP_SET),
				_name(name){}


private:
	virtual const std::string &_getGroupItem(const TSV & fields, std::string &placeholder) const override{
		return _name;
	}

private:
	std::string _name;

};

#endif

