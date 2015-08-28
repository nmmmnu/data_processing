#include <cstdint>
#include <iostream>

#include "processor.h"

// ==========================================

void Processor::process(){
	TSV fields;
	std::string fld;

	for(std::string line; getline(_input, line);){
		fields.load(line);

		const std::string &fld_data = getField(fields);

		if (fld != fld_data ){
			_store(fld);

			fld = fld_data;
		}

		if (getSkip(fields))
			continue;

		_aggregate(fields, fld);
	}

	// store remaining elements
	_store(fld);
}

void Processor::_aggregate(const TSV & fields, const std::string & fld){
	for(auto & cc : _collectors)
		cc->aggregate(fields, fld);
}

void Processor::_store(const std::string & fld){
	for(auto & cc : _collectors)
		cc->store(fld);
}

void Processor::print() const{
	for(const auto & cc : _collectors)
		cc->print();
}
