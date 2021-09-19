#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
#include <regex>

using namespace std;

class Stat {
public:
	Stat(const string& fileName) {
		input.open(fileName);
		read();
		//if (wrds_amount > 0)
			//transfer_data();
	}
	void read() {
		regex regular("([A-Za-z0-9]+)([^A-Za-z0-9]*)");
		cmatch result;
		while (!input.eof()) {
			getline(input, tmp_string);
			while (regex_search(tmp_string.c_str(), result, regular)) {
				buffer[result[1]]++;
				wrds_amount++;
				tmp_string = result.suffix();
			}
		}
	}
	const map<string, int>& getStat() {
		return buffer;
	}
	const int getWrdsAmount() {
		return wrds_amount;
	}


private:
	ifstream input;
	string tmp_string;
	//map<int, list<string>> data;
	map<string, int> buffer;
	int wrds_amount;
};

struct cmp {

	bool operator()(const pair<string, int>& p1, const pair<string, int>& p2) {
		return (p1.second > p2.second);
	}
};

class CSVWriter {
public:
	CSVWriter(Stat &stat) {
		this->stat = &stat;
		transfer_data();
	}
	void write(string fileName) {
		output.open(fileName);		
		for (vector<pair<string, int>> :: iterator it = sorted_stat.begin(); it != sorted_stat.end(); it++) {
			output << it->first << "," << it->second << "," << 
			(double)it->second/stat->getWrdsAmount() * 100 << "\n";
			
		}
	}
	void transfer_data() {
		for (map<string, int> ::const_iterator it = stat->getStat().begin(); it != stat->getStat().end(); it++) {
			sorted_stat.push_back(make_pair(it->first, it->second));
		}
		sort(sorted_stat.begin(), sorted_stat.end(), cmp());
	}
	
private:
	ofstream output;
	Stat* stat;
	vector<pair<string, int>> sorted_stat;
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