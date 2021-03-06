#pragma once
#include <string>
#include <fstream>
#include <regex>
#include <map>
#include <queue>
#include "FileException.h"

using namespace std;

class ConfParser {
private:
	const string fileName;
	ifstream input;
	map<unsigned int, string> cmds;
	queue<unsigned int> ex_order;
public:
	ConfParser(const string fileName);
	void parse();
	void ParseBlocksInit();
	void ParseExOrder();
	map<unsigned int, string>& getCmds();
	queue<unsigned int>& getOrder();
};

