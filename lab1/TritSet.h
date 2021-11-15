#pragma once
#include "Trit.h"
#include <iostream>
#include <vector>
#define uint unsigned int
#define trits_per_uint (8 * sizeof(uint) / 2)
#define trits2size(tritsAmount) (((tritsAmount) * 2 + (8 * sizeof(uint) - 1)) / (8 * sizeof(uint)))
class TritSet {
private:
	uint tritSize;																				
	uint initSize;
	std::vector<uint> data;
	void setValue(uint value, uint index);
	const uint getValue(uint index) const;
	void resize(uint lastIndex);
public:
	TritSet();
	TritSet(uint tritsAmount);
	TritSet(TritSet&& other) noexcept;
	const uint capacity() const;
	void shrink();
	size_t cardinality(Trit value);
	void trim(size_t lastIndex);
	size_t length();

	class ProxyTrit {
	public:
		ProxyTrit(TritSet* set, uint tritIndex) {
			this->set = set;
			this->tritIndex = tritIndex;
			if (tritIndex / trits_per_uint == 0)
				offset = tritIndex * 2;
			else
				offset = (tritIndex % (trits_per_uint)) * 2;
		}

		void operator=(Trit value) {
			if (set->capacity() < trits2size(tritIndex + 1)) {
				if (value == Trit::Unknown)
					return;
				set->resize(trits2size(tritIndex + 1));
			}

			uint mask = value << offset;
			set->setValue(set->getValue(tritIndex) | mask, tritIndex);
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
		uint tritIndex;
		uint offset;
		const Trit getTrit() const {
			if (set->capacity() < trits2size(tritIndex + 1))
				return Trit::Unknown;

			uint mask = 3 << offset;
			uint result = (set->getValue(tritIndex) & mask) >> offset;

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
	TritSet::ProxyTrit operator[](uint tritIndex);
	friend TritSet operator&(TritSet& setA, TritSet& setB);
	friend TritSet operator|(TritSet& setA, TritSet& setB);
	friend TritSet operator!(TritSet& set);
};
