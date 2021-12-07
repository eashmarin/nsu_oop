#pragma once
#include "Worker.h"
#include <regex>
class Griper: public Worker {
private:
	vector<string>* data;
	vector<string> new_data;
	const string word;
public:
	Griper(vector<string>* data, const string word = "");
	virtual void execute();
	virtual void readFile();
	virtual void writeFile() const;
	virtual void grep();
	virtual void sort();
	virtual void replace();
	virtual void dump() const;
	virtual pair<bool, bool> haveIO() const;
};

