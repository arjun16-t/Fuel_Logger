#include "login.h"

Login::Login() 
    : id{nullptr}, pass{nullptr} {}

Login::Login(std::string id, std::string pass)
    : id{id}, pass{pass} {}

bool Login::authentication(std::string id_s, std::string pass_s) {
    if (id != id_s || pass != pass_s) {
        return false;
    }
    return true;
}

// int main() {
//     Login login("admin", "admin");
//     std::string id_user, pass_user;

//     std::cout << "Enter Login Id: ";
//     std::cin >> id_user;
//     std::cout << "Enter Password: ";
//     std::cin >> pass_user;

//     if (login.authentication(id_user, pass_user)) {
//         std::cout << "Login Successful" << std::endl;
//     } else {
//         std::cout << "Login Failed" << std::endl;
//     }
// }