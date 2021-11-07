#include "TritSet.h"

void TritSet::DEBUG() {
	for (int i = 0; i < data.size(); i++) {
		std::cout << "data[" << i << "] = " << data[i] << std::endl;
	}
}

void TritSet::resize(uint lastIndex) {
	uint uintSize = (round)(lastIndex * 2 / (sizeof(uint) * 8)) + 1;					// —делать параметром не посл индекс, а размер (tritSize) 
	data.resize(uintSize);
	this->current_size = lastIndex;
}

TritSet::TritSet() {
	current_size = 0;
	default_size = 0;
}

TritSet::TritSet(int size){
	default_size = size;
	resize(size);
}
TritSet::TritSet(const TritSet& other) {
	this->resize(other.current_size);
	for (int i = 0; i < this->capacity(); i++) {
		this->data[i] = other.data[i];
	}
}
const int TritSet::capacity() const {
	return data.size();
}
uint TritSet::getValue(uint index) const {
	if (capacity() <= uint_index(index))
		return Unknown;
	return data[uint_index(index)];
}
void TritSet::setValue(uint value, uint index) {
	data[uint_index(index)] = value;
}
void TritSet::shrink() {
	int i = current_size - 1;
	while (i > 0 && getValue(i) == 0)
		i--;
	if (i == 0)
		resize(default_size);
	else
		resize(i);
}
std::string TritSet::trit2str(Trit value) {
	switch (value) {
	case 1:
		return "False";
	case 2:
		return "True";
	default:
		return "Unknown";
	}
}
TritSet::ProxyTrit TritSet::operator[](int index) {
	ProxyTrit trit(this, index);
	return trit;
}
TritSet operator&(TritSet& setA, TritSet& setB) {									// Ќе измен€ть размер множеств-операндов
	int expandSize = setA.capacity() < setB.capacity() ? setB.current_size : setA.current_size;
	TritSet result(expandSize);
	
	for (int i = 0; i < expandSize; i++) 
		result[i] = setA[i] & setB[i];

	return std::move(result);
}

TritSet operator|(TritSet& setA, TritSet& setB) {
	int expandSize = setA.capacity() < setB.capacity() ? setB.current_size : setA.current_size;
	TritSet result(expandSize);

	for (int i = 0; i < expandSize; i++)
		result[i] = setA[i] | setB[i];

	return std::move(result);
}

TritSet operator!(TritSet& set) {
	int size = set.current_size;
	TritSet result(size);
	
	for (int i = 0; i < size; i++)
		result[i] = !set[i];
	
	return std::move(result);
}
