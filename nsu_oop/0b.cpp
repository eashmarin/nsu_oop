#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>

using namespace std;

class Stat {
public:
	Stat(const string& fileName) {
		input.open(fileName);
		read();
		if (wrds_amount > 0)
			transfer_data();
		iterator = data.end();
	}
	void read() {
		while (!input.eof()) {
			getline(input, tmp_string);
			if (tmp_string != "") {
				buffer[tmp_string]++;
				wrds_amount++;
			}
		}
	}
	void transfer_data() {  
		for (map<string, int> ::iterator it = buffer.begin(); it != buffer.end(); it++) 
			data[it->second].push_back(it->first);
		
	}
	pair<int, list<string>> getNextWrd() {
		iterator--;
		return make_pair(iterator->first, iterator->second);
	}
	int getSize() {
		return data.size();
	}
	const int getWrdsAmount() {
		return wrds_amount;
	}


private:
	ifstream input;
	string tmp_string;
	map<int, list<string>> data;
	map<string, int> buffer;
	map<int, list<string>> ::iterator iterator;
	int wrds_amount;
};

class CSVWriter {
public:
	CSVWriter(Stat &stat) {
		this->stat = &stat;
	}
	void write(string fileName) {
		output.open(fileName);
		int size = stat->getSize();
		for (int i = 0; i < size; i++) {
			pair<int, list<string>> p = stat->getNextWrd();
			for (list<string> ::iterator list_it = p.second.begin(); list_it != p.second.end(); list_it++) 
				output <<  *list_it << "," << p.first << "," << 
				(double)p.first/stat->getWrdsAmount() * 100 << "\n";
			
		}
	}
private:
	ofstream output;
	Stat* stat;
};

int main(int argc, char *argv[]) {

	//const string fileName = argv[0];
	//getline(cin, fileName);

	Stat stat("input.txt");
	//cout << argv[1] << "\n" << argv[2];
	CSVWriter write(stat);
	write.write("output.csv");

	return 0;
}