#include "Reader.h"

Reader::Reader(string fileName)
	: fileName(fileName) {
	
	readFile();
}

const vector<string>& Reader::getContent() {
	return content;
}

void Reader::readFile() {
	ifstream input(fileName);
	string buffer;
	while (!input.eof()) {
		getline(input, buffer);
		content.push_back(buffer + '\n');
	}
	input.close();
}

void Reader::writeFile() {}

void Reader::grep() {}

void Reader::sort() {}

void Reader::replace() {}

void Reader::dump() {}