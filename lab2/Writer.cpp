#include "Writer.h"

Writer::Writer(vector<string>* data, string fileName)
    : data(data), fileName(fileName) {}

void Writer::execute(){
    ofstream output(fileName);
    if (!output)
        throw FileException(fileName);

    for (auto& it : *data)
        output << it;
}

pair<bool, bool> Writer::haveIO() const{
    return make_pair(true, false);
}
