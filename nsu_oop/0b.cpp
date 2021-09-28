#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
#include <regex>

using namespace std;

class cmp {
public:
	bool operator()(const pair<string, int>& p1, const pair<string, int>& p2) {
		return (p1.second > p2.second);
	}
};

class Stat {
public:
	Stat(const string fileName) {
		input.open(fileName);
		read();
		input.close();
		transfer_data();
		sort(data.begin(), data.end(), cmp());
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
	void transfer_data() {
		map<string, int> ::const_iterator it;
		for (it = buffer.begin(); it != buffer.end(); it++)
			data.push_back(make_pair(it->first, it->second));
	}
	const vector<pair<string, int>>& getStat() {
		return data;
	}
	const int& getWrdsAmount() {
		return wrds_amount;
	}


private:
	ifstream input;
	string currLine;
	map<string, int> buffer;
	vector<pair<string, int>> data;
	int wrds_amount;
};

class CSVWriter {
public:
	CSVWriter(Stat &stat) {
		this->stat = &stat;
	}
	void write(string fileName) {
		output.open(fileName);		
		vector<pair<string, int>> ::const_iterator it;
		for (it = stat->getStat().begin(); it != stat->getStat().end(); it++) {
			output << it->first << "," << it->second << "," << 
			(double)it->second/stat->getWrdsAmount() * 100 << "%\n";
		}
	}
	
private:
	ofstream output;
	Stat* stat;
};

int main(int argc, char *argv[]) {
	string inputName = "input.txt";
	string outputName = "output.csv";
	/*if (argc > 1) {
		inputName = argv[1];
		outputName = argv[2];
	}*/
	Stat stat(inputName);
	CSVWriter write(stat);
	write.write(outputName);

	return 0;
}