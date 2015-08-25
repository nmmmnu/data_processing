#ifndef _MAIN_MEDIA_COLLECTORS_H
#define _MAIN_MEDIA_COLLECTORS_H

#include "collect_counter.h"
#include "collect_aggregate.h"

// ==========================================

class CollectMediaLike : public ICollectCounter{
public:
	using ICollectCounter::ICollectCounter;

private:
	virtual uint64_t _getCount(const TSV & fields) const override{
		return fields.like();
	}
};

// ==========================================

class CollectMediaComment : public ICollectCounter{
public:
	using ICollectCounter::ICollectCounter;

private:
	virtual uint64_t _getCount(const TSV & fields) const override{
		return fields.comment();
	}
};

// ==========================================

class CollectMediaLikeCountry : public ICollectAggregate{
public:
	using ICollectAggregate::ICollectAggregate;

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
	using ICollectAggregate::ICollectAggregate;

private:
	virtual const std::string &_getItem(const TSV & fields) const override{
		return fields.country();
	}

	virtual uint64_t _getCount(const TSV & fields) const override{
		return fields.comment();
	}

};

#endif

