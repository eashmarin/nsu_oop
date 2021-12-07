#pragma once
#include "Worker.h"
#include <fstream>
class Writer: public Worker {
private:
	string fileName;
	vector<string>* data;
public:
	Writer(vector<string>* data, string fileName = "");
	virtual void execute();
	virtual void readFile();
	virtual void writeFile() const;
	virtual void grep();
	virtual void sort();
	virtual void replace();
	virtual void dump() const;
	virtual pair<bool, bool> haveIO() const;
};

