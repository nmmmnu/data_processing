#ifndef _UNIQUESET_H
#define _UNIQUESET_H

#include <unordered_set>

class UniqueSet{
public:
	constexpr static const auto MAX_SIZE = 10000;

public:
	bool exists(const std::string &element, const std::string &group){
		if (group == _group){
			if (_uniq.size() > MAX_SIZE)
				return true;

			if (_uniq.find(element) != _uniq.end())
				return true;
		}else{
			_uniq.clear();

			_group = group;
		}

		_uniq.insert(element);

		return false;
	}

private:
	std::string			_group;
	std::unordered_set<std::string>	_uniq;
};

#endif

