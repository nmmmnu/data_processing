#ifndef _COLLECT_TAG_TOTAL_H
#define _COLLECT_TAG_TOTAL_H

#include "collect.h"


// ==========================================

class CollectMediaTotal : public ICollect{
public:
	CollectMediaTotal(const std::string &prefix, const std::string &name) :
				ICollect(prefix),
				_name(name){}

private:
	std::string			_name;

	uint64_t			_count		= 0;

private:
	virtual void _collect(const TSV & fields, const std::string & tag) override;
	virtual void _store(const std::string & tag) override;
	virtual void _print() const override;
};

#endif

