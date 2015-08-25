#ifndef _COLLECT_TAG_LIKE_TOTAL_H
#define _COLLECT_TAG_LIKE_TOTAL_H

#include "collect.h"

#include <set>

// ==========================================

class CollectMediaLike : public ICollect{
public:
	CollectMediaLike(const std::string &prefix, const std::string &name, unsigned const topCount) :
				ICollect(prefix),
				_name(name),
				_topCount(topCount){}

private:
	std::string			_name;
	unsigned			_topCount;

	std::set<MyPair,MyPairComp>	data;
	uint64_t			data_single		= 0;
	uint64_t			data_minimum		= 0;
	bool				data_hc			= false	;

private:
	virtual void _aggregate(const TSV & fields, const std::string & tag) override;
	virtual void _store(const std::string & tag) override;
	virtual void _print() const override;

};

#endif

