#include "Dumper.h"

Dumper::Dumper(vector<string>* content, string fileName)
	: content(content), fileName(fileName) {}

void Dumper::execute(){
	dump();
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
	for (auto& it : *content)
		output << it;
	output.close();
}
