#include "collect_media_total.h"

#include <iostream>

void CollectMediaTotal::_collect(const TSV & fields, const std::string & tag){
	// empty
}

void CollectMediaTotal::_store(const std::string & tag){
	++_count;
}

void CollectMediaTotal::_print() const{
	std::cout
		<< _prefix	<< "\t"
		<< _name	<< "\t"
		<< _name	<< "\t"
		<< _count	<< "\n";
}

