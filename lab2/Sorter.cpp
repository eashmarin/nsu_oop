#include "Sorter.h"

Sorter::Sorter(vector<string>* data)
	: data(data) {
}

void Sorter::execute(){
	sort();

}

void Sorter::readFile()
{
}

void Sorter::writeFile() const
{
}

void Sorter::grep()
{
}

void Sorter::sort(){
	std::sort(data->begin(), data->end());
}

void Sorter::replace()
{
}

void Sorter::dump() const
{
}

pair<bool, bool> Sorter::haveIO() const{
	return make_pair(true, true);
}
