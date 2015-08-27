#ifndef _COLLECT_COUNTER_H
#define _COLLECT_COUNTER_H

#include "collect.h"

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
	ICollectCounter(const std::string &prefix, unsigned const topCount, const std::string &name) :
				ICollectAggregate(prefix, topCount, OP_SET),
				_name(name){}


private:
	virtual const std::string &_getGroupItem(const TSV & fields) override{
		return _name;
	}

private:
	std::string _name;

};

#endif

