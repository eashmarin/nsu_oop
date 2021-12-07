#include "FileException.h"

FileException::FileException(std::string fileName)
    : runtime_error("Failed to open file " + fileName){
}
