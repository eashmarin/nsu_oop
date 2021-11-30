#include "Dumper.h"

Dumper::Dumper(string fileName, vector<string>& content)
	: fileName(fileName), content(content)
{
	dump();
}

const vector<string>& Dumper::getContent() {
	return content;
}

void Dumper::readFile()
{
}

void Dumper::writeFile()
{
}

void Dumper::grep()
{
}

void Dumper::sort()
{
}

void Dumper::replace()
{
}

void Dumper::dump(){
	ofstream output;
	for (auto& it : content)
		output << it;
	output.close();
}
