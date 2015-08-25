#ifndef _COLLECT_MEDIA_COMMENT_TOTAL_H
#define _COLLECT_MEDIA_COMMENT_TOTAL_H

#include "collect_counter.h"

class CollectMediaComment : public ICollectCounter{
public:
	CollectMediaComment(const std::string &prefix, const std::string &name, unsigned const topCount) :
				ICollectCounter(prefix, name, topCount){}

private:
	virtual uint64_t _getCount(const TSV & fields) const override{
		return fields.comment();
	}
};

#endif

