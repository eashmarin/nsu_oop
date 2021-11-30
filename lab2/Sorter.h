#pragma once
#include "Worker.h"
#include <regex>
#include <algorithm>
#include <vector>
class Sorter: public Worker {
private:
	vector<string> content;
	vector<string> sortedContent;
public:
	Sorter(vector<string>& content);
	void arrange_content();
	virtual const vector<string>& getContent();
	virtual void readFile();
	virtual void writeFile();
	virtual void grep();
	virtual void sort();
	virtual void replace();
	virtual void dump();
};

