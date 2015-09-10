#ifndef _MAIN_MEDIA_COLLECTORS_H
#define _MAIN_MEDIA_COLLECTORS_H

#include "processor.h"
#include "uniqueset.h"

#include "collect_counter.h"
#include "collect_aggregate_user.h"

#include <iostream>

// ==========================================

class CollectUserAllTags : public ICollectAggregateUser{
public:
	CollectUserAllTags(const std::string &prefix, unsigned const topCount) :
				ICollectAggregateUser(prefix, topCount, OP_COUNT){}

private:
	virtual const std::string &_getGroupItem(const TSV & fields){
		return _item;
	}

private:
	const std::string _item = "tags";
};

// ==========================================

class Processor2User : public Processor{
public:
	Processor2User(std::istream & input, const std::vector<ICollect *> &collectors) :
				Processor(input, collectors){}

private:
	virtual const std::string &getField(TSV &fields) const override{
		return fields.user();
	}

	virtual bool getSkip(TSV &fields){
		if (fields.tag() == _emptyTag)
			return true;

		return uniq.exists(fields.tag(), fields.user());
	};

private:
	UniqueSet	uniq;

	const std::string	_emptyTag = "--DIVAKA--";
};

#endif
