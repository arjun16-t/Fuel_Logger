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
    std::string filepath;
    
public:
    Log(std::string filepath);

    bool set_record(Txn txn);
    std::map<std::string, Txn> get_record();

    // To be implemented
    bool search();
};

#endif