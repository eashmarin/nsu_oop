#include "Griper.h"

Griper::Griper(vector<string>* content, string word)
	: content(content), word(word) {}

void Griper::execute(){
	grep();
	*content = new_content;
}

void Griper::readFile()
{
}

void Griper::writeFile()
{
}

void Griper::grep() {
	for (auto& it : *content) {
		regex reg("([A-Za-z0-9_-]+)([!:;*.?\n]*)( *)");
		smatch result;
		string buffer = it;
		while (regex_search(buffer, result, reg)) {
			if (result[1] == word)
				new_content.push_back(it);
			buffer = result.suffix();
		}
	}
}

void Griper::sort()
{
}

void Griper::replace()
{
}

void Griper::dump()
{
}
