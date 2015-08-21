#ifndef _PROCESSOR_H
#define _PROCESSOR_H

#include <string>
#include <unordered_map>
#include <set>

#include "tsv.h"
#include "tag.h"

// ==========================================

class Processor{
public:
	constexpr
	static const auto	TOP_COUNT	= MASTER_TOP_COUNT;

	constexpr
	static const auto	COUNTRY_RESERVE	= MASTER_COUNTRY_RESERVE;

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

	void countryProcess(const TSV & fields, std::string & tag){
		if (tag != fields.tag()){
			countryStoreData(tag);

			tag = fields.tag();
			country_single_tag.clear();
		}

		++country_single_tag[ fields.country() ];
	}

	void countryStoreData(const std::string & tag){
		if (! tag.empty())
			_countryStoreData(tag);
	}

	void print() const;

private:
	std::string filename;

	std::unordered_map<std::string, std::set<Tag,TagComp> >		country;
	std::unordered_map<std::string, uint64_t>			country_single_tag;
	std::unordered_map<std::string, uint64_t>			country_minimums;

private:
	void _countryStoreData(const std::string & tag){
		for ( const auto & pair : country_single_tag ){
			auto & country_name  = pair.first;
			auto & country_count = pair.second;

			auto & country_set = country[country_name];

			if (country_minimums[country_name] > country_count)
				continue;

			country_set.insert( { tag, country_count } );

			if (country_set.size() > TOP_COUNT){
				auto iterator = country_set.cbegin();

				const Tag &pp = *iterator;
				country_minimums[country_name] = pp.second;

				// remove minimum
				country_set.erase(iterator);
			}
		}
	}
};

#endif

