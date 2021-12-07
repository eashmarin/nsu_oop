#include "Writer.h"

Writer::Writer(vector<string>* data, string fileName)
    : data(data), fileName(fileName) {}

void Writer::execute(){
    writeFile();
}

void Writer::readFile()
{
}

void Writer::writeFile() const {
    ofstream output(fileName);
    if (!output)
        throw FileException(fileName);

    for (auto& it : *data)
        output << it;
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

void Writer::dump() const {
}

pair<bool, bool> Writer::haveIO() const{
    return make_pair(true, false);
}
