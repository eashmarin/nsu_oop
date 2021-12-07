#include "ConfExecutor.h"

ConfExecutor::ConfExecutor(const string fileName)
	: fileName(fileName) {}

void ConfExecutor::execute(){
	try {
		ConfParser parser(fileName);
		parser.parse();
		cmds = parser.getCmds();
		ex_order = parser.getOrder();
		bool haveOutput = false;
		while (!ex_order.empty()) {
			unsigned int currId = ex_order.front();
			ex_order.pop();

			Worker* w = createWorker(cmds[currId]);

			if (haveOutput != w->haveIO().first)
				throw logic_error("execution order is invalid");

			haveOutput = w->haveIO().second;

			w->execute();
			delete w;
		}
		if (haveOutput)
			throw logic_error("execution order is invalid!");
	}
	catch (exception& e) {
		cout << "ERROR: " << e.what() << endl;
	}
}

Worker* ConfExecutor::createWorker(const string cmd) {
	regex reg("([A-Za-z0-9]+)( *)([A-Za-z0-9_.]*)( *)([A-Za-z0-9_.]*)( *)");
	smatch reg_result;
	regex_search(cmd, reg_result, reg);

	string func = reg_result[1];
	string arg1 = reg_result[3];
	string arg2 = reg_result[5];

	if (func == "readfile")
		return new Reader(&data, arg1);
	if (func == "sort")
		return new Sorter(&data);
	if (func == "replace")
		return new Replacer(&data, arg1, arg2);
	if (func == "grep")
		return new Griper(&data, arg1);
	if (func == "dump")
		return new Dumper(&data, arg1);
	if (func == "writefile")
		return new Writer(&data, arg1);

	throw logic_error("Program can't execute command \"" + func +"\" in " + fileName);
}
