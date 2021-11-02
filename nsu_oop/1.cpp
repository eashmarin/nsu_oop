#include <iostream>
#include <vector>
#define uint unsigned int
#define uint_index(index) (index * 2 / 8 / sizeof(uint))
//#define True 00
//#define Unknown 10
//#define False 01
//#define trit_size 2
using namespace std;
// 00 - True, 01 - False, 10 - Unknown
// 00 - Unknown, 01 - False, 10 - True
enum Trit{
	False = 1, 
	True = 2, 
	Unknown = 0
};

string int2Trit(uint value) {
	switch (value) {
	case 1:
		return "False";
	case 2:
		return "True";
	default:
		return "Unknown";
	}
}

class TritSet {
private:

	int size;
	int index;
	vector<uint> data;
	int size_remained;
public:
	TritSet() {
		size = 0;
	}
	TritSet(const int size) {
		resize(size);
	}
	void resize(uint size) {
		this->size = size;
		size_remained = (round)(size * 2 / (sizeof(uint) * 8)) + 1;
		//size_remained += ((size / 2) % (size_remained)) / 2;
		data.resize(size_remained);
	}
	const int capacity() {
		return data.size();
	}
	uint& getValue(uint index) {
		return data[uint_index(index)];
	}
	class ProxyTrit {
	public:
		ProxyTrit(TritSet* set, int index) {
			this->set = set;
			this->index = index;
			if (uint_index(index) == 0)
				offset = index;
			else
				offset = (index % uint_index(index)) * 2 - 2;
		}
		void operator=(Trit value) {
			if (value == Unknown)
				return;
			if (set->capacity() <= index * 2 / 8 / sizeof(uint)) {
				set->resize(index);
			}
			uint mask = value << offset;
			set->getValue(index) |= mask;
		}
		friend ostream& operator<< (std::ostream &out, TritSet::ProxyTrit trit) {
			uint mask = 3 << trit.offset;
			return out << int2Trit((trit.set->getValue(trit.index) & mask) >> (trit.offset));
		}

	private:
		TritSet* set;
		uint index;
		uint offset;
	};
	ProxyTrit operator[](int index) {
		ProxyTrit trit(this, index);
		return trit;
	}

};


int main() {
	TritSet set(500);
	set[499] = Trit::False;
	set[500] = Trit::True;
	set[498] = Trit::True;
	set[1000] = Trit::True;
	cout << "capacity = " << set.capacity() << endl;
	//cout << set[19] << " - " << &set[19] << endl;
	//cout << sizeof(uint);
	//cout << set.capacity() << endl;
	return 0;
}