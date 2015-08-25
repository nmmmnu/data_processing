#ifndef _aggregate_TAG_TOTAL_H
#define _aggregate_TAG_TOTAL_H

#include "collect.h"

#include <set>

// ==========================================

class CollectTagTotal : public ICollect{
public:
	CollectTagTotal(const std::string &prefix, const std::string &name, unsigned const topCount) :
				ICollect(prefix),
				_name(name),
				_topCount(topCount){}

private:
	std::string			_name;
	unsigned			_topCount;

	std::set<MyPair,MyPairComp>	data;
	uint64_t			count_single_tag	= 0;
	uint64_t			count_minimum		= 0;

private:
	virtual void _aggregate(const TSV & fields, const std::string & tag) override;
	virtual void _store(const std::string & tag) override;
	virtual void _print() const override;
};

#endif

