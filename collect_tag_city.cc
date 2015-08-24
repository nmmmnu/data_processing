#include "collect_tag_city.h"

#include <iostream>

void CollectTagCity::_collect(const TSV & fields, const std::string & tag){
	auto field_city = fields.country() + ":" + fields.city();

	++data_single_tag[ field_city ];
}

void CollectTagCity::_store(const std::string & tag){
	for ( const auto & pair : data_single_tag ){
		auto & data_name  = pair.first;
		auto & data_count = pair.second;

		auto & data_set = data[data_name];

		if (data_minimums[data_name] > data_count)
			continue;

		data_set.insert( { tag, data_count } );

		if (data_set.size() > _topCount){
			auto iterator = data_set.cbegin();

			const MyPair &pp = *iterator;
			data_minimums[data_name] = pp.second;

			// remove minimum
			data_set.erase(iterator);
		}
	}

	data_single_tag.clear();
}

void CollectTagCity::_print() const{
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

