#include <cstdint>
#include <iostream>

#include "processor.h"

// ==========================================

void Processor::process(){
	TSV fields;
	std::string fld;

	for(std::string line; getline(_input, line);){
		fields.load(line);

		if (fld != fields.get(_fieldID)){
			_store(fld);

			fld = fields.get(_fieldID);
		}

		_collect(fields, fld);
	}

	// store remaining elements
	_store(fld);
}

void Processor::_collect(const TSV & fields, const std::string & fld){
	for(auto & cc : _collectors)
		cc->collect(fields, fld);
}

void Processor::_store(const std::string & fld){
	for(auto & cc : _collectors)
		cc->store(fld);
}

void Processor::print() const{
	for(const auto & cc : _collectors)
		cc->print();
}
