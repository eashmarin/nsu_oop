#pragma once
#include "Trit.h"
#include <iostream>
#include <vector>
#define uint unsigned int
#define uint_index(index) (index * 2 / 8 / sizeof(uint))
class TritSet {
private:
	int current_size;
	int default_size;
	std::vector<uint> data;
	std::string trit2str(Trit value);
	void setValue(uint value, uint index);
	uint getValue(uint index) const;
	void resize(uint lastIndex);
public:
	TritSet();
	TritSet(int size);
	void DEBUG();
	const int capacity() const;
	void shrink();
	class ProxyTrit {
	public:
		ProxyTrit(TritSet* set, int index) {
			this->set = set;
			this->index = index;
			if (uint_index(index) == 0)
				offset = index * 2;
			else
				offset = (index % uint_index(index)) * 2 - 2;
		}

		void operator=(Trit value) {
			if (value == Unknown)
				return;
			if (set->capacity() <= uint_index(index)) {
				set->resize(index);
			}
			uint mask = value << offset;
			set->setValue(set->getValue(index) | mask, index);
		}
		bool operator== (Trit value) {
			if (set->capacity() <= uint_index(index)) {
				if (value == Unknown)
					return true;
				else
					return false;
			}
			return value == getTrit();
		}
		std::ostream& operator<< (std::ostream& out) {

			return out << set->trit2str(getTrit());
		}

	private:
		TritSet* set;
		uint index;
		uint offset;
		Trit getTrit() {
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
};
