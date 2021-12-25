#pragma once
#include "Worker.h"
#include <fstream>
class Dumper: public Worker {
private:
	const string fileName;
	vector<string>* data;
public:
	Dumper(vector<string>* data, const string fileName = "");
	virtual void execute();
	virtual pair<bool, bool> haveIO() const;
};

