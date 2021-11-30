#include "Sorter.h"

Sorter::Sorter(vector<string>* content)
	: content(content) {
}

/*void Sorter::arrange_content() {
	for (auto& it : *content) {
		regex reg("([^ ]+)( *)");
		smatch result;
		string buffer = it;
		while (regex_search(buffer, result, reg)) {
			sortedContent.push_back(result[1]);
			buffer = result.suffix();
		}
		//sortedContent.at(sortedContent.size() - 1) += "\n";
	}
}*/

void Sorter::execute(){
	sort();

}

void Sorter::readFile()
{
}

void Sorter::writeFile()
{
}

void Sorter::grep()
{
}

void Sorter::sort(){
	std::sort(content->begin(), content->end());
}

void Sorter::replace()
{
}

void Sorter::dump()
{
}
