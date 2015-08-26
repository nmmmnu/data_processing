#ifndef _MAIN_MEDIA_COLLECTORS_H
#define _MAIN_MEDIA_COLLECTORS_H

#include "collect_aggregate.h"
#include "collect_counter.h"

// ==========================================

class CollectMediaLike : public ICollectCounter{
public:
	CollectMediaLike(const std::string &prefix, unsigned const topCount, const std::string &name) :
				ICollectCounter(prefix, topCount, name){}

private:
	virtual uint64_t _getCount(const TSV & fields) const override{
		return fields.like();
	}
};

// ==========================================

class CollectMediaComment : public ICollectCounter{
public:
	CollectMediaComment(const std::string &prefix, unsigned const topCount, const std::string &name) :
				ICollectCounter(prefix, topCount, name){}

private:
	virtual uint64_t _getCount(const TSV & fields) const override{
		return fields.comment();
	}
};


// ==========================================

class CollectMediaLikeCountry : public ICollectAggregate{
public:
	CollectMediaLikeCountry(const std::string &prefix, unsigned const topCount) :
				ICollectAggregate(prefix, topCount, OP_SET){}

private:
	virtual const std::string &_getGroupItem(const TSV & fields, std::string &placeholder) const override{
		return fields.country();
	}

	virtual uint64_t _getCount(const TSV & fields) const override{
		return fields.like();
	}
};

// ==========================================

class CollectMediaCommentCountry : public ICollectAggregate{
public:
	CollectMediaCommentCountry(const std::string &prefix, unsigned const topCount) :
				ICollectAggregate(prefix, topCount, OP_SET){}

private:
	virtual const std::string &_getGroupItem(const TSV & fields, std::string &placeholder) const override{
		return fields.country();
	}

	virtual uint64_t _getCount(const TSV & fields) const override{
		return fields.comment();
	}
};

#endif

