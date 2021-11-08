#pragma once
#include "Trit.h"
#include <iostream>
#include <vector>
#define uint unsigned int
#define trit2uint(value) (value * 2 / 8 / sizeof(uint))
class TritSet {
private:
	int current_size;																				// Убрать size-поля
	int default_size;
	std::vector<uint> data;
	void setValue(uint value, uint index);
	const uint getValue(uint index) const;
	void resize(uint lastIndex);
public:
	TritSet();
	TritSet(int size);
	TritSet(const TritSet& other);
	const int capacity() const;
	void shrink();
	class ProxyTrit {
	public:
		ProxyTrit(TritSet* set, int index) {
			this->set = set;
			this->index = index;
			if (trit2uint(index) == 0)
				offset = index * 2;
			else
				offset = (index % trit2uint(index)) * 2;
		}

		void operator=(Trit value) {
			if (value == Unknown)
				return;
			if (set->capacity() <= trit2uint(index)) {
				set->resize(index);
			}
			uint mask = value << offset;
			set->setValue(set->getValue(index) | mask, index);
		}
		const bool operator== (Trit value) const {
			return value == getTrit();
		}
		friend Trit operator&(ProxyTrit tritA, ProxyTrit tritB) {
			if (tritA == Trit::False || tritB == Trit::False)
				return Trit::False;
			if (tritA == Trit::Unknown || tritB == Trit::Unknown)
				return Trit::Unknown;
			return Trit::True;
		}
		friend Trit operator|(ProxyTrit tritA, ProxyTrit tritB) {
			if (tritA == Trit::True || tritB == Trit::True)
				return Trit::True;
			if (tritA == Trit::False && tritB == Trit::False)
				return Trit::False;
			return Trit::Unknown;
		}
		friend Trit operator!(ProxyTrit trit) {
			if (trit == Trit::True)
				return Trit::False;
			if (trit == Trit::False)
				return Trit::True;
			return Trit::Unknown;
		}

	private:
		TritSet* set;
		uint index;
		uint offset;
		Trit getTrit() const {
			if (set->capacity() <= trit2uint(index))
				return Trit::Unknown;

			uint mask = 3 << offset;
			uint result = (set->getValue(index) & mask) >> offset;
			switch (result) {
			case 1:
				return Trit::False;
			case 2:
				return Trit::True;
			default:
				return Trit::Unknown;
			}
		}
	};
	TritSet::ProxyTrit operator[](int index);
	friend TritSet operator&(TritSet& setA, TritSet& setB);
	friend TritSet operator|(TritSet& setA, TritSet& setB);
	friend TritSet operator!(TritSet& set);
};
