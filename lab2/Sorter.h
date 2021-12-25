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
	virtual pair<bool, bool> haveIO() const;
};

