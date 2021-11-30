#include "FileWriter.h"

FileWriter::FileWriter(string& fileName, vector<string>& content)
	: fileName(fileName), content(content){
	writeFile();
}

const vector<string>& FileWriter::getContent() {
	return content;
}

void FileWriter::readFile()
{
}

void FileWriter::writeFile() {
	ofstream output(fileName);
	for (auto& it : content)
		output << it;
	output.close();
}

void FileWriter::grep()
{
}

void FileWriter::sort()
{
}

void FileWriter::replace()
{
}

void FileWriter::dump()
{
}
