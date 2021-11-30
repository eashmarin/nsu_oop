#include "Writer.h"

Writer::Writer(vector<string>* content, string fileName)
    : content(content), fileName(fileName) {}

void Writer::execute(){
    writeFile();
}

void Writer::readFile()
{
}

void Writer::writeFile() {
    ofstream output(fileName);
    for (auto& it : *content)
        output << it;
    output.close();
}

void Writer::grep()
{
}

void Writer::sort()
{
}

void Writer::replace()
{
}

void Writer::dump()
{
}
