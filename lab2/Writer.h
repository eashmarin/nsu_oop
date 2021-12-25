#pragma once
#include "Worker.h"
#include <fstream>
class Writer: public Worker {
private:
	string fileName;
	vector<string>* data;
public:
	Writer(vector<string>* data, string fileName = "");
	virtual void execute();
	virtual pair<bool, bool> haveIO() const;
};

