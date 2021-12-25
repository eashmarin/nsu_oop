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

			unique_ptr<Worker> w = createWorker(cmds[currId]);

			if (haveOutput != w->haveIO().first)
				throw logic_error("execution order is invalid");

			haveOutput = w->haveIO().second;

			w->execute();
		}
		if (haveOutput)
			throw logic_error("execution order is invalid!");
	}
	catch (exception& e) {
		cout << "ERROR: " << e.what() << endl;
	}
}

unique_ptr<Worker> ConfExecutor::createWorker(const string cmd) {
	regex reg("([A-Za-z0-9]+)( *)([A-Za-z0-9_.]*)( *)([A-Za-z0-9_.]*)( *)");
	smatch reg_result;
	regex_search(cmd, reg_result, reg);

	string func = reg_result[1];
	string arg1 = reg_result[3];
	string arg2 = reg_result[5];

	if (func == "readfile")
		return make_unique<Reader>(&data, arg1);
	if (func == "sort")
		return make_unique<Sorter>(&data);
	if (func == "replace")
		return make_unique<Replacer>(&data, arg1, arg2);
	if (func == "grep")
		return make_unique<Grepper>(&data, arg1);
	if (func == "dump")
		return make_unique<Dumper>(&data, arg1);
	if (func == "writefile")
		return make_unique<Writer>(&data, arg1);

	throw logic_error("Program can't execute command \"" + func +"\" in " + fileName);
}
