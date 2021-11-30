#include "Writer.h"

Writer::Writer(string fileName, vector<string>& content)
    : fileName(fileName), content(content) {
    writeFile();
}

const vector<string>& Writer::getContent(){
    return content;
}

void Writer::readFile()
{
}

void Writer::writeFile() {
    ofstream output(fileName);
    for (auto& it : content)
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
