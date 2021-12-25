#pragma once
#include <string>
#include <vector>
#include "FileException.h"
using namespace std;
class Worker {
public:
	virtual void execute() = 0;
	virtual pair<bool, bool> haveIO() const = 0;
};

