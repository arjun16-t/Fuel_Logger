#ifndef _FILE_HANDLING_H_
#define _FILE_HANDLING_H_

#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include "fillups.h"

class Log {
    std::ifstream fin;
    std::ofstream fout;

    bool set_record(std::string filepath, Txn txn);
    std::map<std::string, Txn> get_record(std::string filepath);

    // To be implemented
    bool search(std::string filepath, Txn txn);
};

#endif