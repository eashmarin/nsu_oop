#pragma once
#include "Worker.h"
#include <fstream>
class Dumper: public Worker {
private:
	const string fileName;
	vector<string>* data;
public:
	Dumper(vector<string>* data, const string fileName = "");
	virtual void execute();
	virtual void readFile();
	virtual void writeFile() const;
	virtual void grep();
	virtual void sort();
	virtual void replace();
	virtual void dump() const;
	virtual pair<bool, bool> haveIO() const;
};

