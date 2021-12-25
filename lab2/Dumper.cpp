#include "Dumper.h"

Dumper::Dumper(vector<string>* data, const string fileName)
	: data(data), fileName(fileName) {}

void Dumper::execute(){
	ofstream output(fileName);
	if (!output)
		throw FileException(fileName);

	for (auto& it : *data)
		output << it;
}

pair<bool, bool> Dumper::haveIO() const{
	return make_pair(true, true);
}
