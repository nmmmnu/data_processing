#ifndef _COLLECT_TAG_LIKE_COUNTRY_H
#define _COLLECT_TAG_LIKE_COUNTRY_H

#include "collect.h"

#include <unordered_map>
#include <set>

// ==========================================

class CollectMediaLikeCountry : public ICollect{
public:
	CollectMediaLikeCountry(const std::string &prefix, unsigned const topCount) :
				ICollect(prefix),
				_topCount(topCount){}

private:
	unsigned			_topCount;

	std::unordered_map<std::string, std::set<MyPair,MyPairComp> >	data;
	std::unordered_map<std::string, uint64_t>			data_single;
	std::unordered_map<std::string, uint64_t>			data_minimums;

private:
	virtual void _collect(const TSV & fields, const std::string & tag) override;
	virtual void _store(const std::string & tag) override;
	virtual void _print() const override;

};

#endif

