#pragma once
#include "Worker.h"
#include <regex>
class Replacer: public Worker {
private:
	vector<string>* data;
	const string word1;
	const string word2;
public:
	Replacer(vector<string>* data, const string word1 = "", const string word2 = "");
	virtual void execute();
	virtual void readFile();
	virtual void writeFile() const;
	virtual void grep();
	virtual void sort();
	virtual void replace();
	virtual void dump() const;
	virtual pair<bool, bool> haveIO() const;
};

