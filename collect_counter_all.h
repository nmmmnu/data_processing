#ifndef _COLLECT_COUNTER_ALL_H
#define _COLLECT_COUNTER_ALL_H

#include "collect.h"

#include <set>

/*
This class have following responsibility:
========================================
It does not collects anything,
but act as count(*) in SQL.
It produce single row with single number.
*/

class CollectCounterAll : public ICollect{
public:
	CollectCounterAll(const std::string &prefix, const std::string &name) :
				CollectCounterAll(prefix, name, name){}

	CollectCounterAll(const std::string &prefix, const std::string &name1, const std::string &name2) :
				ICollect(prefix),
				_name1(name1),
				_name2(name2){}

private:
	std::string			_name1;
	std::string			_name2;

	uint64_t			_count		= 0;

private:
	virtual void _aggregate(const TSV & fields, const std::string & tag) override{
		// empty
	}

	virtual void _store(const std::string & tag) override;
	virtual void _print() const override;
};

#endif

