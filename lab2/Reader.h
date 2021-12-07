#pragma once
#include "Worker.h"
#include <fstream>
#include <vector>
class Reader: public Worker {
protected:
	const string fileName;
	vector<string>* data;
public:
	Reader(vector<string>* data, const string fileName = "");
	virtual void execute();
	virtual void readFile();
	virtual void writeFile() const;
	virtual void grep();
	virtual void sort();
	virtual void replace() ;
	virtual void dump() const;
	virtual pair<bool, bool> haveIO() const;
};

