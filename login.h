#ifndef _LOGIN_H_
#define _LOGIN_H_
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

class Login {
    std::string id;
    std::string pass;

public:
    Login();
    Login(std::string id, std::string pass);
    bool authentication(std::string id, std::string pass);
};

#endif