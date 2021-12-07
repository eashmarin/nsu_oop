#include "ConfParser.h"

ConfParser::ConfParser(const string fileName)
	: fileName(fileName) {}

void ConfParser::parse() {		
	input.open(fileName);
	if (!input)
		throw FileException(fileName);

	ParseBlocksInit();
	ParseExOrder();

	input.close();
}

void ConfParser::ParseBlocksInit() {
	string currLine = "";
	getline(input, currLine);
	if (currLine != "desc")
		throw logic_error("can't find \"desc\" in the beginning of " + fileName);

	getline(input, currLine);
	while (currLine != "csed" && !input.eof()) {
		regex reg("([0-9]+)( * = *)([A-Za-z0-9]+ *[A-Za-z0-9_.]* *[A-Za-z0-9_.]* *)");
		smatch reg_result;
		regex_search(currLine, reg_result, reg);
		


		if (reg_result.size() == 0)
			throw invalid_argument("invalid workflow syntax");

		int id = stoi(reg_result[1]);
		string cmd = reg_result[3];

		if (cmds.count(id) > 0)
			throw logic_error("id \"" + (string)reg_result[1] + "\" is defined multiple times in " + fileName);

		cmds[id] = cmd;

		getline(input, currLine);
	}
	if (currLine != "csed")
		throw logic_error("can't find \"csed\" in the end of scheme description in " + fileName);
}

void ConfParser::ParseExOrder(){
	while (!input.eof()) {
		string buffer;
		input >> buffer;

		if (buffer != "->") {
			if (cmds.count(stoi(buffer)) == 0)
				throw invalid_argument("invalid workflow syntax"); 
			ex_order.push(stoi(buffer));
		}
	}
}

map<unsigned int, string>& ConfParser::getCmds(){
	return cmds;
}

queue<unsigned int>& ConfParser::getOrder(){
	return ex_order;
}
