#ifndef _MAIN_MEDIA_COLLECTORS_H
#define _MAIN_MEDIA_COLLECTORS_H

#include "collect_counter.h"
#include "collect_aggregate.h"

// ==========================================

class CollectMediaLike : public ICollectCounter{
public:
//	using ICollectCounter::ICollectCounter;
	CollectMediaLike(const std::string &prefix, const std::string &name, unsigned const topCount) :
				ICollectCounter(prefix, name, topCount){}

private:
	virtual uint64_t _getCount(const TSV & fields) const override{
		return fields.like();
	}
};

// ==========================================

class CollectMediaComment : public ICollectCounter{
public:
//	using ICollectCounter::ICollectCounter;
	CollectMediaComment(const std::string &prefix, const std::string &name, unsigned const topCount) :
				ICollectCounter(prefix, name, topCount){}

private:
	virtual uint64_t _getCount(const TSV & fields) const override{
		return fields.comment();
	}
};

// ==========================================

class CollectMediaLikeCountry : public ICollectAggregate{
public:
//	using ICollectAggregate::ICollectAggregate;
	CollectMediaLikeCountry(const std::string &prefix, unsigned const topCount) :
				ICollectAggregate(prefix, topCount){}

private:
	virtual const std::string &_getItem(const TSV & fields) const override{
		return fields.country();
	}

	virtual uint64_t _getCount(const TSV & fields) const override{
		return fields.like();
	}

};

// ==========================================

class CollectMediaCommentCountry : public ICollectAggregate{
public:
//	using ICollectAggregate::ICollectAggregate;
	CollectMediaCommentCountry(const std::string &prefix, unsigned const topCount) :
				ICollectAggregate(prefix, topCount){}

private:
	virtual const std::string &_getItem(const TSV & fields) const override{
		return fields.country();
	}

	virtual uint64_t _getCount(const TSV & fields) const override{
		return fields.comment();
	}

};

#endif

