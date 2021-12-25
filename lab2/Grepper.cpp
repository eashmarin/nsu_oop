#include "Grepper.h"

Grepper::Grepper(vector<string>* data, const string word)
	: data(data), word(word) {}

void Grepper::execute(){
	for (auto& it : *data) {
		int pos = it.find(word);
		string buffer = it;
		if (pos >= 0)
			new_data.push_back(it);
	}
	*data = new_data;
}

pair<bool, bool> Grepper::haveIO() const{
	return make_pair(true, true);
}
