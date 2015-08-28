#ifndef _MAIN_MEDIA_COLLECTORS_H
#define _MAIN_MEDIA_COLLECTORS_H

#include "processor.h"

#include "collect_aggregate.h"
#include "collect_counter.h"

#include <iostream>

// ==========================================

class CollectMediaLike : public ICollectCounter{
public:
	CollectMediaLike(const std::string &prefix, unsigned const topCount, const std::string &name) :
				ICollectCounter(prefix, topCount, name){}

private:
	virtual uint64_t _getCount(const TSV & fields) override{
		return fields.like();
	}
};

// ==========================================

class CollectMediaComment : public ICollectCounter{
public:
	CollectMediaComment(const std::string &prefix, unsigned const topCount, const std::string &name) :
				ICollectCounter(prefix, topCount, name){}

private:
	virtual uint64_t _getCount(const TSV & fields) override{
		return fields.comment();
	}
};


// ==========================================

class CollectMediaLikeCountry : public ICollectAggregate{
public:
	CollectMediaLikeCountry(const std::string &prefix, unsigned const topCount) :
				ICollectAggregate(prefix, topCount, OP_SET){}

private:
	virtual const std::string &_getGroupItem(const TSV & fields) override{
		return fields.country();
	}

	virtual uint64_t _getCount(const TSV & fields) override{
		return fields.like();
	}
};

// ==========================================

class CollectMediaCommentCountry : public ICollectAggregate{
public:
	CollectMediaCommentCountry(const std::string &prefix, unsigned const topCount) :
				ICollectAggregate(prefix, topCount, OP_SET){}

private:
	virtual const std::string &_getGroupItem(const TSV & fields) override{
		return fields.country();
	}

	virtual uint64_t _getCount(const TSV & fields) override{
		return fields.comment();
	}
};

// ==========================================

class ProcessorMedia : public Processor{
public:
	ProcessorMedia(std::istream & input, const std::vector<ICollect *> &collectors) :
				Processor(input, collectors){}

private:
	virtual const std::string &getField(TSV &fields) const override{
		return fields.media();
	}
};

#endif

