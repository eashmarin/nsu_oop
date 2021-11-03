#include <iostream>
#include <vector>
#define uint unsigned int
#define uint_index(index) (index * 2 / 8 / sizeof(uint))
using namespace std;
// 11 - Unknown, 01 - False, 10 - True
enum Trit{
	False = 1, 
	True = 2, 
	Unknown = 3
};

string trit2str(uint value) {
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
	vector<uint> data;
public:
	void DEBUG() {
		for (int i = 0; i < data.size(); i++) {
			cout << "data[" << i << "] = " << data[i] << endl;
		}
	}
	TritSet() {
		size = 0;
	}
	TritSet(const int size) {
		resize(size);
	}
	void resize(uint lastIndex) {
		uint uintSize = (round)(lastIndex * 2 / (sizeof(uint) * 8)) + 1;					// Сделать параметром не посл индекс, а размер (tritSize) 
		data.resize(uintSize);
		this->size = lastIndex;
	}
	const int capacity() const {
		return data.size();
	}
	uint getValue(uint index) const {
		if (capacity() <= uint_index(index))
			return Unknown;
		return data[uint_index(index)];
	}
	void setValue(uint value, uint index) {
		data[uint_index(index)] = value;
	}
	void shrink() {
		int i = size - 1;
		while (i > 0 && getValue(i) == 0)
			i--;
		resize(i);
	}
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
		friend ostream& operator<< (std::ostream &out, TritSet::ProxyTrit trit) {
			
			return out << trit2str(trit.getTrit());
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

int main(int argc, char* argv[]) {
	TritSet set(500);
	cout << "capacity before = " << set.capacity() << endl;
	set[0] = Trit::False;
	set[1] = Trit::True;
	set[3] = Trit::True;
	set[447] = Trit::True;
	set.shrink();
	cout << "capacity after shrink = " << set.capacity() << endl;
	if (set[55500] == Unknown)
		cout << "TRUE!!!" << endl;
	cout << "set[447] = " << set[447] << endl;

	return 0;
}