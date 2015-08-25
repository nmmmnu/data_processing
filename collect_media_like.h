#ifndef _COLLECT_TAG_LIKE_TOTAL_H
#define _COLLECT_TAG_LIKE_TOTAL_H

#include "collect_counter.h"

class CollectMediaLike : public ICollectCounter{
public:
	CollectMediaLike(const std::string &prefix, const std::string &name, unsigned const topCount) :
				ICollectCounter(prefix, name, topCount){}

private:
	virtual uint64_t _getCount(const TSV & fields) const override{
		return fields.like();
	}
};

#endif

