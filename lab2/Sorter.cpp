#include "Sorter.h"

Sorter::Sorter(vector<string>* data)
	: data(data) {
}

void Sorter::execute(){
	std::sort(data->begin(), data->end());

}

pair<bool, bool> Sorter::haveIO() const{
	return make_pair(true, true);
}
