#ifndef _COLLECT_H
#define _COLLECT_H

#include "tsv.h"
#include "mypair.h"

class ICollect{
public:
	ICollect(const std::string &prefix) : _prefix(prefix){}

//	virtual ~ICollect();

	void aggregate(const TSV & fields, const std::string & data){
		_aggregate(fields, data);
	}

	void store(const std::string & data){
		if (! data.empty())
			_store(data);
	}

	void print() const{
		_print();
	}

protected:
	std::string _prefix;

private:
	virtual void _aggregate(const TSV & fields, const std::string & data) = 0;
	virtual void _store(const std::string & data) = 0;
	virtual void _print() const = 0;

};

#endif

