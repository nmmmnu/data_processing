#include "collect_media_comment_country.h"

#include <iostream>

void CollectMediaCommentCountry::_aggregate(const TSV & fields, const std::string & med){
	data_single[ fields.country() ] = fields.comment();
}

void CollectMediaCommentCountry::_store(const std::string & med){
	for ( const auto & pair : data_single ){
		const auto & data_name  = pair.first;
		const auto & data_count = pair.second;

		if (data_minimums[data_name] > data_count)
			continue;

		auto & data_set = data[data_name];

		data_set.insert( { med, data_count } );

		if (data_set.size() > _topCount){
			auto iterator = data_set.cbegin();

			const MyPair &pp = *iterator;
			data_minimums[data_name] = pp.second;

			// remove minimum
			data_set.erase(iterator);
		}
	}

	data_single.clear();
}

void CollectMediaCommentCountry::_print() const{
	for (const auto & pair : data){
		const auto & country_name = pair.first;
		const auto & country_set  = pair.second;

		for (const auto & tp : country_set){
			const auto & tp_med   = tp.first;
			const auto & tp_count = tp.second;

			std::cout
				<< _prefix	<< "\t"
				<< country_name	<< "\t"
				<< tp_med	<< "\t"
				<< tp_count	<< "\n";
		}
	}
}

