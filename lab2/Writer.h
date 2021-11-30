#pragma once
#include "Worker.h"
#include <fstream>
class Writer: public Worker {
private:
	string fileName;
	vector<string>* content;
public:
	Writer(vector<string>* content, string fileName);
	virtual void execute();
	virtual void readFile();
	virtual void writeFile();
	virtual void grep();
	virtual void sort();
	virtual void replace();
	virtual void dump();
};

