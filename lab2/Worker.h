#pragma once
#include <string>
#include <vector>
#include "FileException.h"
using namespace std;
class Worker {
public:
	virtual void execute() = 0;
	virtual void readFile() = 0;
	virtual void writeFile() const = 0;
	virtual void grep() = 0;
	virtual void sort() = 0;
	virtual void replace() = 0;
	virtual void dump() const = 0;
	virtual pair<bool, bool> haveIO() const = 0;
};

