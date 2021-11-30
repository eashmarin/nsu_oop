#pragma once
#include "Worker.h"
#include <regex>
#include <sstream>
class Replacer: public Worker {
private:
	vector<string>* content;
	vector<string> arranged_content;
	string word1;
	string word2;
public:
	Replacer(vector<string>* content, string word1, string word2);
	void arrange_content();
	void arrange_content_back();
	virtual void execute();
	virtual void readFile();
	virtual void writeFile();
	virtual void grep();
	virtual void sort();
	virtual void replace();
	virtual void dump();
};

