#ifndef _COLLECT_DOUBLE_H
#define _COLLECT_DOUBLE_H

#include "collect.h"

#include <unordered_map>
#include <set>

class ICollectAggregateUser : public ICollect{
public:
	constexpr static const char OP_SET	= 0;
	constexpr static const char OP_SUM	= 1;
	constexpr static const char OP_COUNT	= 2;

public:
	ICollectAggregateUser(const std::string &prefix, unsigned const topCount, char const op = OP_COUNT) :
				ICollect(prefix),
				_topCount(topCount),
				_op(op){}

private:
	typedef std::set<MyPair,MyPairComp> PairSet;

private:
	unsigned	_topCount;
	char		_op;

	std::unordered_map<std::string, uint64_t>	data_single;

private:
	virtual void _store(const std::string & user) override;

	virtual void _aggregate(const TSV & fields, const std::string & tag) override{
		switch(_op){
		case OP_SUM:
			{
				auto count  = _getCount(fields);
				if (count)
					data_single[ _getGroupItem(fields) ] += count;
			}
			return;

		case OP_COUNT:
			++data_single[ _getGroupItem(fields) ];
			return;

		case OP_SET:
		default:
			data_single[ _getGroupItem(fields) ] = _getCount(fields);
			return;
		}
	}

	virtual void _print() const override{
		// none
	}

private:
	virtual const std::string &_getGroupItem(const TSV &fields) = 0;
	virtual uint64_t _getCount(const TSV & fields){
		return 1;
	}

private:
	void _printUserData(const PairSet &data_set, const std::string &user) const;

};

#endif

