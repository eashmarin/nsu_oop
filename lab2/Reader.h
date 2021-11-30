#pragma once
#include "Worker.h"
#include <fstream>
#include <vector>
class Reader: public Worker {
protected:
	string fileName;
	vector<string>* content;
public:
	Reader(vector<string>* content, string fileName);
	virtual void execute();
	virtual void readFile();
	virtual void writeFile();
	virtual void grep();
	virtual void sort();
	virtual void replace() ;
	virtual void dump();
};

