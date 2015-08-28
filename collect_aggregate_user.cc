#include "collect_aggregate_user.h"

#include <iostream>

void ICollectAggregateUser::_store(const std::string & user){	// user
	PairSet data_set;

	for ( const auto & pair : data_single ){
		const auto & data_item  = pair.first;		// tag
		const auto & data_count = pair.second;		// count

		data_set.insert( { data_item, data_count } );

		if (data_set.size() > _topCount){
			// remove minimum
			data_set.erase(data_set.cbegin());
		}
	}

	data_single.clear();

	_printUserData(data_set, user);
}

void ICollectAggregateUser::_printUserData(const PairSet &data_set, const std::string & user) const{
	for (const auto & pair : data_set){
		const auto & data_item  = pair.first;		// country
		const auto & data_count = pair.second;

		std::cout
			<< _prefix	<< "\t"
			<< user		<< "\t"
			<< data_item	<< "\t"
			<< data_count	<< "\n";
	}
}

