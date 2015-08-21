#ifndef _COLLECT_COUNTRY_CITY_H
#define _COLLECT_COUNTRY_CITY_H

#include <unordered_map>
#include <set>

#include "tsv.h"
#include "tag.h"

// ==========================================

class CollectCountryCity{
public:
	explicit
	CollectCountryCity(const std::string &prefix, unsigned topCount, unsigned reserve = 0) :
		_topCount(topCount),
		_reserve(reserve),
		_prefix(prefix){}

	void collect(const TSV & fields, std::string & tag);
	void store(const std::string & tag);
	void print() const;
	void cleanup(bool doReserve = false);

private:
	unsigned _topCount;
	unsigned _reserve;

	std::string _prefix;

	std::unordered_map<std::string, std::set<Tag,TagComp> >		data;
	std::unordered_map<std::string, uint64_t>			data_single_tag;
	std::unordered_map<std::string, uint64_t>			data_minimums;
};

#endif

