#include "ConfParser.h"

ConfParser::ConfParser(string fileName)
	: fileName(fileName) {}

unsigned int ConfParser::string2int(string id) {
	unsigned int result = 0;
	for (int index = id.length() - 1; index >= 0; index--) {
		result += (id[index] - '0') * pow(10, id.length() - index - 1);
	}
	return result;
}

void ConfParser::parse() {
	ifstream input(fileName);

	string id = "";
	string cmd = "";
	string buffer = "";
	getline(input, buffer);
	getline(input, buffer);
	while (buffer != "csed") {

		regex reg("([0-9]+)( * = *)([A-Za-z0-9]+ *[A-Za-z0-9_.]* *[A-Za-z0-9_.]* *)");
		smatch result;
		regex_search(buffer, result, reg);

		id = result[1];
		cmd = (string)result[3];
		cmds[string2int(id)] = cmd;

		getline(input, buffer);
	}
	while (!input.eof()) {
		input >> buffer;
		if (buffer != "->") {
			Worker* w = createWorker(cmds[string2int(buffer)]);
			w->execute();
		}
	}
}

Worker* ConfParser::createWorker(string cmd) {

	regex reg("([A-Za-z0-9]+)( *)([A-Za-z0-9_.]*)( *)([A-Za-z0-9_.]*)( *)");
	smatch result;
	regex_search(cmd, result, reg);

	if (result[1] == "readfile")
		return new Reader(&content, result[3]);
	if (result[1] == "sort")
		return new Sorter(&content);
	if (result[1] == "replace")
		return new Replacer(&content, result[3], result[5]);
	if (result[1] == "grep")
		return new Griper(&content, result[3]);
	if (result[1] == "dump")
		return new Dumper(&content, result[3]);
	if (result[1] == "writefile")
		return new Writer(&content, result[3]);
}

