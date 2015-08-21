#include <cstdint>
#include <cstdio>

#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <array>
#include <unordered_map>
#include <set>

constexpr
const auto MASTER_TOP_COUNT		= 1000;
constexpr
const auto MASTER_COUNTRY_RESERVE	= 200;
constexpr
const auto VERSION			= "1.0";

// ==========================================

class TSV{
public:
	constexpr
	static const char	DELIMITER	= '\t';

	constexpr
	static const char	FIELDS_COUNT	= 10;

private:
	constexpr
	static const char	POS_COUNTRY	= 0;
	constexpr
	static const char	POS_TAG		= 3;

private:
	std::array<std::string,FIELDS_COUNT>	_data;

public:
	TSV() = default;

	TSV(const std::string & line){
		load(line);
	}

	const std::string & country() const{
		return _data[POS_COUNTRY];
	}

	const std::string & tag() const{
		return _data[POS_TAG];
	}

	void load(const std::string & line);
};

// ==========================================

typedef std::pair<std::string, uint64_t> TagPair;

struct TagPairComp{
	bool operator() (const TagPair & a, const TagPair & b) const{
		// http://www.cplusplus.com/reference/set/set/
		// elements are considered equal,
		// if ( ! comp(a, b) && ! comp(b, a) )
		// this is why we use <= instead of just <
		return a.second <= b.second;
	}
};

// ==========================================

class Processor{
public:
	constexpr
	static const auto	TOP_COUNT	= MASTER_TOP_COUNT;

	constexpr
	static const auto	COUNTRY_RESERVE	= MASTER_COUNTRY_RESERVE;

public:
	explicit
	Processor(const char *filename) :
		filename(filename){}

	explicit
	Processor(const std::string & filename) :
		filename(filename){}

	void process(){
		if (filename == "-"){
			std::istream & input = std::cin;
			processFile(input);
		}else{
			std::ifstream input( filename );
			processFile(input);
		}
	}

	void processFile(std::istream & input){
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

	void countryProcess(const TSV & fields, std::string & tag){
		if (tag != fields.tag()){
			countryStoreData(tag);

			tag = fields.tag();
			country_single_tag.clear();
		}

		++country_single_tag[ fields.country() ];
	}

	void countryStoreData(const std::string & tag){
		if (! tag.empty())
			_countryStoreData(tag);
	}

	void print() const{
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

private:
	std::string filename;

	std::unordered_map<std::string, std::set<TagPair,TagPairComp> >	country;
	std::unordered_map<std::string, uint64_t>			country_single_tag;
	std::unordered_map<std::string, uint64_t>			country_minimums;

private:
	void _countryStoreData(const std::string & tag){
		for ( const auto & pair : country_single_tag ){
			auto & country_name  = pair.first;
			auto & country_count = pair.second;

			auto & country_set = country[country_name];

			if (country_minimums[country_name] > country_count)
				continue;

			country_set.insert( { tag, country_count } );

			if (country_set.size() > TOP_COUNT){
				auto iterator = country_set.cbegin();

				const TagPair &pp = *( iterator );
				country_minimums[country_name] = pp.second;

				// remove minimum
				country_set.erase(iterator);
			}
		}
	}
};

// ==========================================

static int printHelp(const char *name);

int main(int argc, char **argv){
	if (argc < 2)
		return printHelp(argv[0]);

	Processor p { argv[1] };

	p.process();
	p.print();

	return 0;
}

// ==========================================

static int printHelp(const char *name){
	constexpr static const auto format = "\t%s %-*s - %s\n";
	constexpr static const auto fpos1 = 11;
	constexpr static const auto fpos2 = 12;

	printf("%s version %s\n", name, VERSION);
	printf("\t%-*s: %u\n",		fpos1, "loop count",	MASTER_TOP_COUNT);
	printf("\t%-*s: %s %s\n",	fpos1, "build",		__DATE__, __TIME__);

	printf("\n");

	printf("Usage\n");
	printf(format, name, fpos2, "[file]",		"Load data from file");
	printf(format, name, fpos2, "-",		"Load data from stdin, usually 10x sloooow :-)");
	printf(format, name, fpos2, "/dev/stdin",	"Load data from stdin (fast, UNIX only)");

	return 1;
}

// ==========================================

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









#if 0

template<typename T>
class Roller{
public:
	Roller() = default;
	Roller(T max) : _max(max){}

	operator bool(){
		return _current == 0;
	}

	T incr(){
		++_current;

		if (_current > _max)
			_current = 0;

		return _current;
	};

private:
	T _max		= 1000;
	T _current	= 0;
};

#endif
