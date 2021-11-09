#include "TritSet.h"

void TritSet::resize(uint newSize) {
	data.resize(newSize);
	tritSize = newSize * trits_per_uint;
}

TritSet::TritSet() {
	tritSize = 0;
	initSize = 0;
}

TritSet::TritSet(uint tritsAmount){
	initSize = tritsAmount;
	resize(trits2size(initSize));
}

TritSet::TritSet(const TritSet& other) {
	resize(other.capacity());
	uint capacity = this->capacity();
	for (int i = 0; i < capacity; i++)
		data[i] = other.data[i];
}

const uint TritSet::capacity() const {
	return data.size();
}

const uint TritSet::getValue(uint index) const {
	if (capacity() < trits2size(index + 1))
		return Unknown;
	return data[index / trits_per_uint];
}

void TritSet::setValue(uint value, uint index) {
	data[(index / trits_per_uint)] = value;
}

void TritSet::shrink() {
	uint counter = tritSize;

	while (counter > 0 && (getValue(counter) == 0 || getValue(counter) == Trit::Unknown)) 
		counter--;
	
	if (counter == 0)
		resize(trits2size(initSize));
	else
		resize(trits2size(counter + 1));
}

TritSet::ProxyTrit TritSet::operator[](uint tritIndex) {
	ProxyTrit trit(this, tritIndex);
	return trit;
}

TritSet operator&(TritSet& setA, TritSet& setB) {
	int expandSize = setA.capacity() < setB.capacity() ? setB.tritSize : setA.tritSize;
	TritSet result(expandSize);
	
	for (int i = 0; i < expandSize; i++) 
		result[i] = setA[i] & setB[i];

	return std::move(result);
}

TritSet operator|(TritSet& setA, TritSet& setB) {
	int expandSize = setA.capacity() < setB.capacity() ? setB.tritSize : setA.tritSize;
	TritSet result(expandSize);

	for (int i = 0; i < expandSize; i++)
		result[i] = setA[i] | setB[i];

	return std::move(result);
}

TritSet operator!(TritSet& set) {
	TritSet result(set.tritSize);

	int size = set.tritSize;
	for (int i = 0; i < size; i++)
		result[i] = !set[i];
	
	return std::move(result);
}
