#ifndef _COLLECT_AGGREGATE_H
#define _COLLECT_AGGREGATE_H

#include "collect.h"

#include <unordered_map>
#include <set>

/*
This class have following responsibility:
========================================
It does basic aggregation,
using "rolling" set, up to topCount,
without any group by.
For example:
===========
top 1000 media sorted by likes, for all countries
*/

class ICollectAggregate : public ICollect{
public:
	constexpr static const char OP_SET	= 0;
	constexpr static const char OP_SUM	= 1;
	constexpr static const char OP_COUNT	= 2;

public:
	ICollectAggregate(const std::string &prefix, unsigned const topCount, char const op) :
				ICollect(prefix),
				_topCount(topCount),
				_op(op){}

private:
	unsigned	_topCount;
	char		_op;

	std::unordered_map<std::string, std::set<MyPair,MyPairComp> >	data;
	std::unordered_map<std::string, uint64_t>			data_single;
	std::unordered_map<std::string, uint64_t>			data_minimums;

private:
	virtual void _aggregate(const TSV & fields, const std::string & tag) override;
	virtual void _store(const std::string & sub_item) override;
	virtual void _print() const override;

private:
	virtual const std::string &_getGroupItem(const TSV & fields) = 0;
	virtual uint64_t _getCount(const TSV & fields){
		return 1;
	}

};

#endif

