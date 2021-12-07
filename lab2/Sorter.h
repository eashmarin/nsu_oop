#pragma once
#include "Worker.h"
#include <regex>
#include <algorithm>
#include <vector>
class Sorter: public Worker {
private:
	vector<string>* data;
public:
	Sorter(vector<string>* data);
	virtual void execute();
	virtual void readFile();
	virtual void writeFile() const;
	virtual void grep();
	virtual void sort();
	virtual void replace();
	virtual void dump() const;
	virtual pair<bool, bool> haveIO() const;
};

