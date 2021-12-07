#include "Replacer.h"

Replacer::Replacer(vector<string>* data, const string word1, const string word2)
	: data(data), word1(word1), word2(word2) {}

void Replacer::execute(){
	replace();
}


void Replacer::readFile()
{
}

void Replacer::writeFile() const {
}

void Replacer::grep()
{
}

void Replacer::sort()
{
}

void Replacer::replace() {
	for (auto& it : *data) {
		int pos = it.find(word1);
		if (pos >= 0)
			it.replace(pos, word1.length(), word2);
	}
}

void Replacer::dump() const {
}

pair<bool, bool> Replacer::haveIO() const{
	return make_pair(true, true);
}
