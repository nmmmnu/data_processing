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

	constexpr static const char	POS_COUNTRY	= 0;
	constexpr static const char	POS_CITY	= 1;
	constexpr static const char	POS_TAG		= 3;
	constexpr static const char	POS_LIKE	= 7;
	constexpr static const char	POS_COMMENT	= 8;

private:
	std::array<std::string,FIELDS_COUNT>	_data;

public:
	TSV() = default;

	TSV(const std::string & line){
		load(line);
	}

	const std::string & get(char const id) const{
		return _data[id];
	}



	const std::string & country() const{
		return get(POS_COUNTRY);
	}

	const std::string & city() const{
		return get(POS_CITY);
	}

	const std::string & tag() const{
		return get(POS_TAG);
	}

	const std::string & like() const{
		return  get(POS_LIKE);
	}

	const std::string & comment() const{
		return get(POS_COMMENT);
	}

	void load(const std::string & line);
};

#endif

