#include "Griper.h"

Griper::Griper(vector<string>* data, const string word)
	: data(data), word(word) {}

void Griper::execute(){
	grep();
	*data = new_data;
}

void Griper::readFile()
{
}

void Griper::writeFile() const{
}

void Griper::grep() {
	for (auto& it : *data) {
		int pos = it.find(word);
		string buffer = it;
		if(pos >= 0) 
			new_data.push_back(it);
	}
}

void Griper::sort()
{
}

void Griper::replace()
{
}

void Griper::dump() const{
}

pair<bool, bool> Griper::haveIO() const{
	return make_pair(true, true);
}
