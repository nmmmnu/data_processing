#ifndef _COLLECT_TAG_COMMENT_COUNTRY_H
#define _COLLECT_TAG_COMMENT_COUNTRY_H

#include "collect_aggregate.h"

class CollectMediaCommentCountry : public ICollectAggregate{
public:
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

