#ifndef _COLLECT_COUNTER_H
#define _COLLECT_COUNTER_H

#include "collect.h"

#include <set>

/*
This class have following responsibility:
========================================
It collects a number such a number of comments,
store it in the "rolling" set,
and keep up to _topCount rows.
*/

class ICollectCounter : public ICollect{
public:
	ICollectCounter(const std::string &prefix, const std::string &name, unsigned const topCount) :
				ICollect(prefix),
				_name(name),
				_topCount(topCount){}

private:
	std::string			_name;
	unsigned			_topCount;

	std::set<MyPair,MyPairComp>	data;
	uint64_t			data_single		= 0;
	uint64_t			data_minimum		= 0;
	bool				data_hitcount		= false	;

private:
	virtual void _aggregate(const TSV & fields, const std::string & tag) override;
	virtual void _store(const std::string & tag) override;
	virtual void _print() const override;

private:
	virtual uint64_t _getCount(const TSV & fields) const = 0;
};

#endif

