#include "Replacer.h"

Replacer::Replacer(vector<string>* content, string word1, string word2)
	: content(content), word1(word1), word2(word2) {}

void Replacer::arrange_content() {
	for (auto& it : *content) {
		regex reg("([A-Za-z0-9_-]+)([.,;:!]*)( *)([\n]*)");
		smatch result;
		string buffer = it;
		while (regex_search(buffer, result, reg)) {
			arranged_content.push_back(result[1]);
			if (result[2].length() > 0)
				arranged_content.push_back(result[2]);
			if (result[3].length() > 0)
				arranged_content.push_back(result[3]);
			if (result[4] == '\n') {
				arranged_content.push_back("\n");
				break;
			}
				
			buffer = result.suffix();
		}
		//sortedContent.at(sortedContent.size() - 1) += "\n";
	}
}

void Replacer::arrange_content_back(){
	auto it = arranged_content.begin();
	for (auto& jt : *content) {
		jt = "";
		for (; *it != "\n"; it++) {
			jt += *it;
		}
		jt += "\n";
		it++;
	}
}

void Replacer::execute(){
	arrange_content();
	replace();
	arrange_content_back();
}


void Replacer::readFile()
{
}

void Replacer::writeFile()
{
}

void Replacer::grep()
{
}

void Replacer::sort()
{
}

void Replacer::replace() {
	for (auto& it : arranged_content) {
		if (it == word1)
			it = word2;
	}
}

void Replacer::dump()
{
}
