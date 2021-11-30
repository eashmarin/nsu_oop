#pragma once
#include "Worker.h"
#include <regex>
class Griper: public Worker {
private:
	vector<string>* content;
	vector<string> new_content;
	string word;
	//vector<string> cntntByLines
public:
	Griper(vector<string>* content, string word);
	virtual void execute();
	virtual void readFile();
	virtual void writeFile();
	virtual void grep();
	virtual void sort();
	virtual void replace();
	virtual void dump();
};

