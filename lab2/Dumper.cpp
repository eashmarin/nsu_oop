#include "Dumper.h"

Dumper::Dumper(vector<string>* data, const string fileName)
	: data(data), fileName(fileName) {}

void Dumper::execute(){
	dump();
}

void Dumper::readFile()
{
}

void Dumper::writeFile() const {
}

void Dumper::grep()
{
}

void Dumper::sort()
{
}

void Dumper::replace()
{
}

void Dumper::dump() const {
	ofstream output(fileName);
	if (!output)
		throw ios_base::failure("failed to open file " + fileName);

	for (auto& it : *data)
		output << it;
}

pair<bool, bool> Dumper::haveIO() const{
	return make_pair(true, true);
}
