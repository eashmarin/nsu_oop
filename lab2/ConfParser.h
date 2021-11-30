#pragma once
//#pragma message ("ConfParser is defined")

#include "Worker.h"
#include "Reader.h"
#include "Writer.h"
#include "Sorter.h"
#include "Replacer.h"
#include "Griper.h"
#include "Dumper.h"
#include <list>
#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <map>

using namespace std;

class ConfParser {
protected:
	string fileName;
	vector<unsigned int> id_order;
	map<unsigned int, string> cmds;
	unsigned int string2int(string id);
	vector<string> content;
public:
	ConfParser();
	ConfParser(string fileName);
	virtual Worker* createWorker(string cmd);
	virtual void parse();
	vector<unsigned int>& getId();
	vector<unsigned int>& getOrder();
};

