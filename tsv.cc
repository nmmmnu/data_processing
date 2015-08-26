#include "tsv.h"

#include <sstream>
#include <iostream>
#include <iomanip>

void TSV::load(const std::string & line){
	std::stringstream ss(line);

	std::string item;

	// skip first...
	std::getline(ss, item, DELIMITER);

	int i = 0 - 1 ;
	while (i < FIELDS_COUNT && std::getline(ss, item, DELIMITER)){
		_data[++i] = std::move(item);
	}
}

uint32_t TSV::_str2int(const std::string & s){
	std::stringstream ss(s);
	int32_t num;
	ss >> num;

	return num < 0 ? 0 : num;
}

void TSV::print() const{
	char i = 0;
	for (const auto &str : _data)
		std::cout << std::setw(3) << (int) i++ << "\t" << str << std::endl;
}

