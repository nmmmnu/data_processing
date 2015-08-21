#include <cstdint>

#include <iostream>
#include <fstream>

#include "processor.h"

// ==========================================

void Processor::process(){
	if (_filename == "-"){
		std::istream & input = std::cin;
		processFile(input);
	}else{
		std::ifstream input(_filename);
		processFile(input);
	}
}

void Processor::processFile(std::istream & input){
	TSV fields;
	std::string tag;

	for(std::string line; getline(input, line);){
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

	for(const auto & cc : _collectors)
		cc->print();
}
