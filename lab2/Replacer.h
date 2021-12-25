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
	virtual pair<bool, bool> haveIO() const;
};

