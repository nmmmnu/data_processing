#ifndef _MAIN_MEDIA_COLLECTORS_H
#define _MAIN_MEDIA_COLLECTORS_H

#include "processor.h"
#include "uniqueset.h"

#include "collect_counter.h"
#include "collect_aggregate_user.h"

#include <iostream>

// ==========================================

class CollectUserTags : public ICollectAggregateUser{
public:
	CollectUserTags(const std::string &prefix, unsigned const topCount) :
				ICollectAggregateUser(prefix, topCount){}

private:
	virtual const std::string &_getGroupItem(const TSV & fields){
		return fields.tag();
	};

};

// ==========================================

class CollectUserCountry : public ICollectAggregateUser{
public:
	CollectUserCountry(const std::string &prefix, unsigned const topCount) :
				ICollectAggregateUser(prefix, topCount){}

private:
	virtual const std::string &_getGroupItem(const TSV & fields){
		return fields.country();
	};

};

// ==========================================

class CollectUserLikes : public ICollectCounter{
public:
	CollectUserLikes(const std::string &prefix, unsigned const topCount, const std::string &name) :
				ICollectCounter(prefix, topCount, name, OP_SUM){}

private:
	virtual uint64_t _getCount(const TSV & fields) override{
		return fields.like();
	}
};

// ==========================================

class CollectUserComments : public ICollectCounter{
public:
	CollectUserComments(const std::string &prefix, unsigned const topCount, const std::string &name) :
				ICollectCounter(prefix, topCount, name, OP_SUM){}

private:
	virtual uint64_t _getCount(const TSV & fields) override{
		return fields.comment();
	}
};

// ==========================================

class CollectUserMedia : public ICollectCounter{
public:
	CollectUserMedia(const std::string &prefix, unsigned const topCount, const std::string &name) :
				ICollectCounter(prefix, topCount, name, OP_SUM){}

private:
	virtual uint64_t _getCount(const TSV & fields) override{
		return 1;
	}
};

// ==========================================

class ProcessorUser : public Processor{
public:
	ProcessorUser(std::istream & input, const std::vector<ICollect *> &collectors) :
				Processor(input, collectors){}

private:
	virtual const std::string &getField(TSV &fields) const override{
		return fields.user();
	}

	virtual bool getSkip(TSV &fields){
		return uniq.exists(fields.media(), fields.user());
	};

private:
	UniqueSet	uniq;

};

#endif
