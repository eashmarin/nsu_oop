#include "Reader.h"

Reader::Reader(vector<string>* content, string fileName)
	: content(content), fileName(fileName) {
}

void Reader::execute(){
	readFile();
}

void Reader::readFile() {
	ifstream input(fileName);
	string buffer;
	while (!input.eof()) {
		getline(input, buffer);
		content->push_back(buffer + '\n');
	}
	input.close();
}

void Reader::writeFile() {}

void Reader::grep() {}

void Reader::sort() {}

void Reader::replace() {}

void Reader::dump() {}