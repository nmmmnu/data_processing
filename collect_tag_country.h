#ifndef _COLLECT_TAG_COUNTRY_H
#define _COLLECT_TAG_COUNTRY_H

#include "collect.h"

#include <unordered_map>
#include <set>

// ==========================================

class CollectTagCountry : public ICollect{
public:
	CollectTagCountry(const std::string &prefix, unsigned const topCount, unsigned const reserve = 0) :
				ICollect(prefix),
				_topCount(topCount),
				_reserve(reserve){}

private:
	unsigned _topCount;
	unsigned _reserve;

	std::unordered_map<std::string, std::set<Tag,TagComp> >		data;
	std::unordered_map<std::string, uint64_t>			data_single_tag;
	std::unordered_map<std::string, uint64_t>			data_minimums;

private:
	virtual void _collect(const TSV & fields, const std::string & tag) override;
	virtual void _store(const std::string & tag) override;
	virtual void _print() const override;
};

#endif

