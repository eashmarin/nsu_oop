#include "Reader.h"

Reader::Reader(vector<string>* data, const string fileName)
	: data(data), fileName(fileName) {
}

void Reader::execute(){
	readFile();
}

void Reader::readFile() {
	ifstream input(fileName);
	if (!input)
		throw ios_base::failure("failed to open file " + fileName);

	string buffer;
	while (!input.eof()) {
		getline(input, buffer);
		data->push_back(buffer + '\n');
	}
}

void Reader::writeFile() const {}

void Reader::grep() {}

void Reader::sort() {}

void Reader::replace() {}

void Reader::dump() const {}

pair<bool, bool> Reader::haveIO() const{
	return make_pair(false, true);
}
