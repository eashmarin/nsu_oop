#pragma once
#include "Worker.h"
#include <regex>
class Grepper: public Worker {
private:
	vector<string>* data;
	vector<string> new_data;
	const string word;
public:
	Grepper(vector<string>* data, const string word = "");
	virtual void execute();
	virtual pair<bool, bool> haveIO() const;
};

