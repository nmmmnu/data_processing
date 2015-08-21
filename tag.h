#ifndef _TAG_H
#define _TAG_H

#include <string>

typedef std::pair<std::string, uint64_t> Tag;

struct TagComp{
	constexpr
	bool operator() (const Tag & a, const Tag & b) const{
		// http://www.cplusplus.com/reference/set/set/
		// elements are considered equal,
		// if ( ! comp(a, b) && ! comp(b, a) )
		// this is why we use <= instead of just <
		return a.second <= b.second;
	}
};

#endif

