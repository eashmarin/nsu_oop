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
	}
	void read() {
		regex regular("([A-Za-z0-9]+)([^A-Za-z0-9]*)");
		smatch result;
		while (!input.eof()) {
			getline(input, currLine);
			while (regex_search(currLine, result, regular)) {
				buffer[result[1]]++;
				wrds_amount++;
				currLine = result.suffix();
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
	string currLine;
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
		sort(data.begin(), data.end(), cmp());
	}
	void write(string fileName) {
		output.open(fileName);	
		vector<pair<string, int>> ::iterator it;
		for (it = data.begin(); it != data.end(); it++) {
			output << it->first << "," << it->second << "," << 
			(double)it->second/stat->getWrdsAmount() * 100 << "%\n";
			
		}
	}
	void transfer_data() {
		map<string, int> ::const_iterator it;
		for (it = stat->getStat().begin(); it != stat->getStat().end(); it++) 
			data.push_back(make_pair(it->first, it->second));
	}
	
private:
	ofstream output;
	Stat* stat;
	vector<pair<string, int>> data;
};

int main(int argc, char *argv[]) {
	string inputName = "input.txt";
	string outputName = "output.csv";
	if (argc > 1) {
		inputName = argv[1];
		outputName = argv[2];
	}
	Stat stat(inputName);
	CSVWriter write(stat);
	write.write(outputName);

	return 0;
}