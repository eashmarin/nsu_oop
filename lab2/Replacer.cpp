#include "Replacer.h"

Replacer::Replacer(vector<string>* data, const string word1, const string word2)
	: data(data), word1(word1), word2(word2) {}

void Replacer::execute(){
	for (auto& it : *data) {
		int pos = it.find(word1);
		if (pos >= 0)
			it.replace(pos, word1.length(), word2);
	}
}

pair<bool, bool> Replacer::haveIO() const{
	return make_pair(true, true);
}
