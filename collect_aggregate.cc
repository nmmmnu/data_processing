#include "collect_aggregate.h"

#include <iostream>

void ICollectAggregate::_aggregate(const TSV & fields, const std::string & med){
	if (_avg){
		++data_single_relative[ _getGroupItem(fields) ];
	}

	switch(_op){
	case OP_SUM:
		{
			auto count  = _getCount(fields);
			if (count)
				data_single[ _getGroupItem(fields) ] += count;
		}
		return;

	case OP_COUNT:
		++data_single[ _getGroupItem(fields) ];
		return;

	case OP_SET:
	default:
		data_single[ _getGroupItem(fields) ] = _getCount(fields);
		return;
	}
}

void ICollectAggregate::_store(const std::string & sub_item){	// tag
	for ( const auto & pair : data_single ){
		const auto & data_item  = pair.first;		// country
		      auto   sub_count  = pair.second;		// count

		if (_avg){
			const uint64_t dividor = data_single_relative[data_item];

			if (dividor == 0)
				continue; // division by zero

			sub_count = sub_count / dividor;
		}

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

	if (_avg){
		data_single_relative.clear();
	}
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
