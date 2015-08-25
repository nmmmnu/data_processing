#include "collect_aggregate.h"

#include <iostream>

void ICollectAggregate::_aggregate(const TSV & fields, const std::string & med){
	data_single[ _getItem(fields) ] = _getCount(fields);
}

void ICollectAggregate::_store(const std::string & sub_item){	// tag
	for ( const auto & pair : data_single ){
		const auto & data_item  = pair.first;		// country
		const auto & sub_count  = pair.second;		// count

		if (data_minimums[data_item] > sub_count)
			continue;

		auto & data_set = data[data_item];

		data_set.insert( { sub_item, sub_count } );

		if (data_set.size() > _topCount){
			auto iterator = data_set.cbegin();

			const MyPair &pp = *iterator;
			data_minimums[data_item] = pp.second;

			// remove minimum
			data_set.erase(iterator);
		}
	}

	data_single.clear();
}

void ICollectAggregate::_print() const{
	for (const auto & pair : data){
		const auto & data_item = pair.first;		// country
		const auto & data_set  = pair.second;

		for (const auto & tp : data_set){
			const auto & sub_item = tp.first;	// tag
			const auto & sub_count   = tp.second;	// count

			std::cout
				<< _prefix	<< "\t"
				<< data_item	<< "\t"
				<< sub_item	<< "\t"
				<< sub_count	<< "\n";
		}
	}
}
