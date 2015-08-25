#include "collect_tag_total.h"

#include <iostream>

void CollectTagTotal::_aggregate(const TSV & fields, const std::string & tag){
	++count_single_tag;
}

void CollectTagTotal::_store(const std::string & tag){
	if (count_minimum > count_single_tag)
		return;

	data.insert( { tag, count_single_tag } );

	if (data.size() > _topCount){
		auto iterator = data.cbegin();

		count_minimum = iterator->second;

		// remove minimum
		data.erase(iterator);
	}

	count_single_tag = 0;
}

void CollectTagTotal::_print() const{
	for (const auto & tp : data){
		const auto & tp_tag   = tp.first;
		const auto & tp_count = tp.second;

		std::cout
			<< _prefix	<< "\t"
			<< _name	<< "\t"
			<< tp_tag	<< "\t"
			<< tp_count	<< "\n";
	}
}

