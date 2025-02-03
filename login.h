#ifndef _LOGIN_H_
#define _LOGIN_H_
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>
#include <map>

class Login {
    std::vector <std::string> id;
    std::map<std::string, std::string> list;
    std::fstream file;

public:
    Login();
    bool authentication(std::string id, std::string pass);
    bool new_user(std::string id, std::string pass);
    bool ask();
};

#endif