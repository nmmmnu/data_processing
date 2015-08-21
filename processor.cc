#include <cstdint>

#include "processor.h"

// ==========================================

void Processor::process(){
	TSV fields;
	std::string tag;

	for(std::string line; getline(_input, line);){
		fields.load(line);

		if (tag != fields.tag()){
			for(auto & cc : _collectors)
				cc->store(tag);

			tag = fields.tag();
		}

		for(auto & cc : _collectors)
			cc->collect(fields, tag);
	}

	// store remaining elements
	for(auto & cc : _collectors)
		cc->store(tag);
}

void Processor::print() const{
	for(const auto & cc : _collectors)
		cc->print();
}
