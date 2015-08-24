#ifndef _MY_PAIR_H
#define _MY_PAIR_H

#include <string>

typedef std::pair<std::string, uint64_t> MyPair;

struct MyPairComp{
	constexpr
	bool operator() (const MyPair & a, const MyPair & b) const{
		// http://www.cplusplus.com/reference/set/set/
		// elements are considered equal,
		// if ( ! comp(a, b) && ! comp(b, a) )
		// this is why we use <= instead of just <
		return a.second <= b.second;
	}
};

#endif

