#ifndef _COLLECT_DOUBLE_H
#define _COLLECT_DOUBLE_H

#include "collect.h"

#include <unordered_map>
#include <set>

class ICollectAggregateUser : public ICollect{
public:
	ICollectAggregateUser(const std::string &prefix, unsigned const topCount) :
				ICollect(prefix),
				_topCount(topCount){}

private:
	typedef std::set<MyPair,MyPairComp> PairSet;

private:
	unsigned	_topCount;

	std::unordered_map<std::string, uint64_t>	data_single;

private:
	virtual void _store(const std::string & user) override;

	virtual void _aggregate(const TSV & fields, const std::string & tag) override{
		++data_single[ _getGroupItem(fields) ];
	}

	virtual void _print() const override{
		// none
	}

private:
	virtual const std::string &_getGroupItem(const TSV &fields) = 0;

private:
	void _printUserData(const PairSet &data_set, const std::string &user) const;

};

#endif

