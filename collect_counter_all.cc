#include "collect_counter_all.h"

#include <iostream>

void CollectCounterAll::_print() const{
	std::cout
		<< _prefix	<< "\t"
		<< _name1	<< "\t"
		<< _name2	<< "\t"
		<< _count	<< "\n";
}
