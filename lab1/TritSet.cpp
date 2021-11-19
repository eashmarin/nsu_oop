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

size_t TritSet::cardinality(Trit value) {
	size_t counter = 0;
	int border = (value == Trit::Unknown) ? this->length() : tritSize;
	for (int index = 0; index < border; index++) {
		if (this->operator[](index) == value)
			counter++;
	}

	return counter;
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

void TritSet::trim(size_t lastIndex) {
	for (int index = lastIndex; index < tritSize; index++)
		this->operator[](index) = Trit::Unknown;
}

size_t TritSet::length() {
	size_t counter = tritSize;

	while (counter > 0 && (this->operator[](counter) == Trit::Unknown))
		counter--;

	if (counter == 0)
		return counter;
	return counter + 1;
}

TritSet::ProxyTrit& TritSet::begin() {
	return *ProxyTrit(this, 0);
}

TritSet::ProxyTrit& TritSet::end() {
	return *ProxyTrit(this, tritSize - 1);
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

	return result;
}

TritSet operator|(TritSet& setA, TritSet& setB) {
	int expandSize = setA.capacity() < setB.capacity() ? setB.tritSize : setA.tritSize;
	TritSet result(expandSize);

	for (int i = 0; i < expandSize; i++)
		result[i] = setA[i] | setB[i];

	return result;
}

TritSet operator!(TritSet& set) {
	TritSet result(set.tritSize);

	int size = set.tritSize;
	for (int i = 0; i < size; i++)
		result[i] = !set[i];
	
	return result;
}
