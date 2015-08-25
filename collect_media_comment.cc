#include "collect_media_comment.h"

#include <iostream>

void CollectMediaComment::_collect(const TSV & fields, const std::string & med){
	if (data_hc)
		return;

	data_single = fields.comment();
	data_hc = true;
}

void CollectMediaComment::_store(const std::string & med){
	data_hc = false;

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

void CollectMediaComment::_print() const{
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
