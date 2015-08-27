#ifndef _MAIN_MEDIA_COLLECTORS_H
#define _MAIN_MEDIA_COLLECTORS_H

#include "processor.h"

#include "collect_aggregate.h"

#include <iostream>

// ==========================================

class CollectTagCountry : public ICollectAggregate{
public:
	CollectTagCountry(const std::string &prefix, unsigned const topCount) :
				ICollectAggregate(prefix, topCount, OP_COUNT){}

private:
	virtual const std::string &_getGroupItem(const TSV & fields) override{
		return fields.country();
	}
};

// ==========================================

class CollectTagCity : public ICollectAggregate{
public:
	CollectTagCity(const std::string &prefix, unsigned const topCount) :
				ICollectAggregate(prefix, topCount, OP_COUNT){}

private:
	virtual const std::string &_getGroupItem(const TSV & fields) override{
		placeholder = fields.country() + ":" + fields.city();

		return placeholder;
	}
private:
	std::string placeholder;

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
	virtual const std::string &_getGroupItem(const TSV & fields) override{
		return _name;
	}
};


// ==========================================

class ProcessorTag : public Processor{
public:
	ProcessorTag(std::istream & input, const std::vector<ICollect *> &collectors) :
				Processor(input, collectors){}

private:
	virtual const std::string &getField(TSV &fields) const override{
		return fields.tag();
	}
};

#endif

