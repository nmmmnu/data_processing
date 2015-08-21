#include "tsv.h"

#include <sstream>

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


