#ifndef _TSV_H
#define _TSV_H

#include <string>
#include <array>

class TSV{
public:
	constexpr
	static const char	DELIMITER	= '\t';

	constexpr
	static const char	FIELDS_COUNT	= 10;

private:
	constexpr static const char	POS_COUNTRY	= 0;
	constexpr static const char	POS_CITY	= 1;
	constexpr static const char	POS_TAG		= 3;

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

	const std::string & city() const{
		return _data[POS_CITY];
	}

	const std::string & tag() const{
		return _data[POS_TAG];
	}

	void load(const std::string & line);
};

#endif

