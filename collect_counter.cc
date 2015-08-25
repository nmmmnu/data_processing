#include "collect_counter.h"

#include <iostream>

void ICollectCounter::_aggregate(const TSV & fields, const std::string & med){
	if (data_hitcount)
		return;

	data_single = _getCount(fields);
	data_hitcount = true;
}

void ICollectCounter::_store(const std::string & med){
	if (data_hitcount == false)
		return;

	data_hitcount = false;

	if (data_minimum > data_single)
		return;

	data.insert( { med, data_single } );

	if (data.size() > _topCount){
		auto iterator = data.cbegin();

		data_minimum = iterator->second;

		// remove minimum
		data.erase(iterator);
	}

	// no need to zeroing...
	// data_single = 0;
}

void ICollectCounter::_print() const{
	for (const auto & tp : data){
		const auto & tp_med   = tp.first;
		const auto & tp_count = tp.second;

		std::cout
			<< _prefix	<< "\t"
			<< _name	<< "\t"
			<< tp_med	<< "\t"
			<< tp_count	<< "\n";
	}
}



