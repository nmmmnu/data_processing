#ifndef _PROCESSOR_H
#define _PROCESSOR_H

#include <string>

#include "tsv.h"
#include "tag.h"

#include "collectcountry.h"
#include "collectcountrycity.h"

// ==========================================

class Processor{
public:
	constexpr
	static const unsigned	TOP_COUNT	= MASTER_TOP_COUNT;

	constexpr
	static const unsigned	COUNTRY_RESERVE	= MASTER_COUNTRY_RESERVE;

	constexpr
	static const unsigned	CITY_RESERVE	= MASTER_CITY_RESERVE;

public:
	explicit
	Processor(const char *filename) :
		filename(filename){}

	explicit
	Processor(const std::string & filename) :
		filename(filename){}

public:
	void process();
	void processFile(std::istream & input);
	void print() const;

private:
	std::string filename;

	CollectCountry     cc1 = CollectCountry     { "TOP_TAG_BY_COUNTRY", TOP_COUNT, COUNTRY_RESERVE };
	CollectCountryCity cc2 = CollectCountryCity { "TOP_TAG_BY_CITY", TOP_COUNT, CITY_RESERVE };
};

#endif

