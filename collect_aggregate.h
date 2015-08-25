#ifndef _COLLECT_AGGREGATE_H
#define _COLLECT_AGGREGATE_H

#include "collect.h"

#include <unordered_map>
#include <set>

/*
This class have following responsibility:
========================================
It does basic aggregation,
using "rolling" set, up to topCount
For example media sorted by likes by country
where country is data_item
and media is subitem
....
*/

class ICollectAggregate : public ICollect{
public:
	ICollectAggregate(const std::string &prefix, unsigned const topCount) :
				ICollect(prefix),
				_topCount(topCount){}

private:
	unsigned			_topCount;

	std::unordered_map<std::string, std::set<MyPair,MyPairComp> >	data;
	std::unordered_map<std::string, uint64_t>			data_single;
	std::unordered_map<std::string, uint64_t>			data_minimums;

private:
	virtual void _aggregate(const TSV & fields, const std::string & tag) override;
	virtual void _store(const std::string & sub_item) override;
	virtual void _print() const override;

private:
	virtual const std::string &_getItem(const TSV & fields) const = 0;
	virtual uint64_t _getCount(const TSV & fields) const = 0;

};

#endif
