#pragma once
#include <iostream>
#include "ConfParser.h"
#include "Worker.h"
#include "Reader.h"
#include "Writer.h"
#include "Sorter.h"
#include "Replacer.h"
#include "Grepper.h"
#include "Dumper.h"
class ConfExecutor{
private:
	const string fileName;
	map<unsigned int, string> cmds;
	queue<unsigned int> ex_order;
	vector<string> data;
	unique_ptr<Worker> createWorker(const string cmd);
public:
	ConfExecutor(const string fileName = "");
	void execute();
};

