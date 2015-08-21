#include <cstdint>

#include <iostream>
#include <fstream>

#include "defs.h"

#include "processor.h"

// ==========================================

void Processor::process(){
	if (filename == "-"){
		std::istream & input = std::cin;
		processFile(input);
	}else{
		std::ifstream input( filename );
		processFile(input);
	}
}

void Processor::processFile(std::istream & input){
	TSV fields;
	std::string tag;

	// remove junk and pre allocate vectors...
	cc1.cleanup(true);

	for(std::string line; getline(input, line);){
		fields.load(line);

		cc1.collect(fields, tag);
	}

	// store remaining elements
	cc1.store(tag);

	// remove junk from memory
	cc1.cleanup();
}

void Processor::print() const{
	cc1.print();
};
