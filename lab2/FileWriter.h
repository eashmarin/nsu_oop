#pragma once
#include "Worker.h"
#include <fstream>
class FileWriter: public Worker {
private:
	string fileName;
	vector<string> content;
public:
	FileWriter(string& fileName, vector<string>& content);
	virtual const vector<string>& getContent();
	virtual void readFile();
	virtual void writeFile();
	virtual void grep();
	virtual void sort();
	virtual void replace();
	virtual void dump();
};

