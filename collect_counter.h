#ifndef _COLLECT_COUNTER_H
#define _COLLECT_COUNTER_H

#include "collect_aggregate.h"

/*
This class have following responsibility:
========================================
It collects a number such a number of comments,
using "rolling" set, up to topCount
For example:
===========
top 1000 media sorted by likes group by country
where
   country = data_item
   media   = sub_item
*/

class ICollectCounter : public ICollectAggregate{
public:
	ICollectCounter(const std::string &prefix, unsigned const topCount, const std::string &name, char const op = OP_SET, bool const avg = false) :
				ICollectAggregate(prefix, topCount, op, avg),
				_name(name){}

private:
	virtual const std::string &_getGroupItem(const TSV & fields) override{
		return _name;
	}

private:
	std::string _name;

};

#endif

