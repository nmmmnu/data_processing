#include "collectcountrycity.h"

#include <iostream>

void CollectCountryCity::collect(const TSV & fields, std::string & tag){
	if (tag != fields.tag()){
		store(tag);

		tag = fields.tag();
		data_single_tag.clear();
	}

	auto city = fields.country() + '\t' + fields.city();

	++data_single_tag[ city ];
}

void CollectCountryCity::store(const std::string & tag){
	if (tag.empty())
		return;

	for ( const auto & pair : data_single_tag ){
		auto & data_name  = pair.first;
		auto & data_count = pair.second;

		auto & data_set = data[data_name];

		if (data_minimums[data_name] > data_count)
			continue;

		data_set.insert( { tag, data_count } );

		if (data_set.size() > _topCount){
			auto iterator = data_set.cbegin();

			const Tag &pp = *iterator;
			data_minimums[data_name] = pp.second;

			// remove minimum
			data_set.erase(iterator);
		}
	}
}

void CollectCountryCity::print() const{
	for (const auto & pair : data){
		auto & city_name = pair.first;
		auto & city_set  = pair.second;

		for (const auto & tp : city_set){
			const auto & tp_tag   = tp.first;
			const auto & tp_count = tp.second;

			std::cout
				<< _prefix	<< "\t"
				<< city_name	<< "\t"
				<< tp_tag	<< "\t"
				<< tp_count	<< "\n";
		}
	}
}

void CollectCountryCity::cleanup(bool doReserve){
	data_single_tag.clear();
	data_minimums.clear();

	if (doReserve && _reserve){
		data_single_tag.reserve(_reserve);
		data_minimums.reserve(_reserve);
	}
}
