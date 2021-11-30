#pragma once
#include <string>
#include <vector>
//#include "Sorter.h"
using namespace std;
class Worker {
public:
	virtual void execute() = 0;
	virtual void readFile() = 0;
	virtual void writeFile() = 0;
	virtual void grep() = 0;
	virtual void sort() = 0;
	virtual void replace() = 0;
	virtual void dump() = 0;
};

