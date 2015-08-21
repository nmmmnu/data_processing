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

	country_minimums.clear();
	country_minimums.reserve(COUNTRY_RESERVE);

	country_single_tag.clear();
	country_single_tag.reserve(COUNTRY_RESERVE);

	for(std::string line; getline(input, line);){
		fields.load(line);

		countryProcess(fields, tag);
	}

	// store remaining elements
	countryStoreData(tag);

	// remove garbage
	country_minimums.clear();
	country_single_tag.clear();
}

void Processor::print() const{
	for (const auto & pair : country){
		auto & country_name = pair.first;
		auto & country_set  = pair.second;

		for (const auto & tp : country_set){
			const auto & tp_tag   = tp.first;
			const auto & tp_count = tp.second;

			std::cout
				<< country_name	<< "\t"
				<< tp_tag	<< "\t"
				<< tp_count	<< "\n";
		}
	}
};
