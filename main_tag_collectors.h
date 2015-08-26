#ifndef _MAIN_MEDIA_COLLECTORS_H
#define _MAIN_MEDIA_COLLECTORS_H

#include "collect_aggregate.h"

// ==========================================

class CollectTagCountry : public ICollectAggregate{
public:
	CollectTagCountry(const std::string &prefix, unsigned const topCount) :
				ICollectAggregate(prefix, topCount, OP_COUNT){}

private:
	virtual const std::string &_getItem(const TSV & fields, std::string &placeholder) const override{
		return fields.country();
	}
};

// ==========================================

class CollectTagCity : public ICollectAggregate{
public:
	CollectTagCity(const std::string &prefix, unsigned const topCount) :
				ICollectAggregate(prefix, topCount, OP_COUNT){}

private:
	virtual const std::string &_getItem(const TSV & fields, std::string &placeholder) const override{
		placeholder = fields.country() + ":" + fields.city();

		return placeholder;
	}
};

// ==========================================

class CollectTagTotal : public ICollectAggregate{
public:
	CollectTagTotal(const std::string &prefix, unsigned const topCount, const std::string &name) :
				ICollectAggregate(prefix, topCount, OP_COUNT),
				_name(name){}

private:
	std::string _name;

private:
	virtual const std::string &_getItem(const TSV & fields, std::string &placeholder) const override{
		return _name;
	}
};

#endif

