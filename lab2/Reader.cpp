#include "Reader.h"

Reader::Reader(vector<string>* data, const string fileName)
	: data(data), fileName(fileName) {
}

void Reader::execute(){
	ifstream input(fileName);
	if (!input)
		throw FileException(fileName);

	string buffer;
	while (!input.eof()) {
		getline(input, buffer);
		data->push_back(buffer + '\n');
	}
}

pair<bool, bool> Reader::haveIO() const{
	return make_pair(false, true);
}
