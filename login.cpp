#include "login.h"

/// @brief Fetched existing user id, pass from file "login.csv"
Login::Login() {
    file.open("login.csv", std::ios::in);
    if (!file) {
        std::cerr << "Error Opening File" << std::endl;
        throw std::runtime_error("File Open Error");
    }

    std::string line;
    std::getline(file, line);

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string temp_id, temp_pass;
        if (getline(ss, temp_id, '|') &&
            getline(ss, temp_pass, '|')) {
            try {
                id.push_back(temp_id);
                list[temp_id] = temp_pass;
            } catch (const std::exception& e) {
                std::cerr << "Error: Invalid data format in line: " << line << std::endl;
                continue;
            }
        } else {
            std::cerr << "Error: Mal formed line: " << line << std::endl;
            throw std::runtime_error("Line Read Error");
        }
    }
    file.close();
}

/// @brief Created new user from id, pass (Checks for existing user)
/// @param id_s ID of new user
/// @param pass_s Pass of new user
/// @return true if created successfully
bool Login::new_user(std::string id_s, std::string pass_s) {
    for (auto c: id) {
        if (c == id_s) {
            throw "User already exists";
            return false;
        }
    }
    file.open("login.csv", std::ios::app);
    if (!file) {
        std::cerr << "Error Opening File" << std::endl;
        throw std::runtime_error("File Open Error");
        return false;
    }
    file << id_s << "|" << pass_s;
    file.close();
    return true;
}

/// @brief Asks for login, pass
/// @param id_s ID of user
/// @param pass_s Pass of user
/// @return true if login successful
bool Login::authentication(std::string id_s, std::string pass_s) {
    bool isPresent = false;
    for (auto c: id) {
        if (c == id_s)
            isPresent = true;
    }
    if (isPresent) {
        if (list[id_s] == pass_s)
            return true;
        else {
            throw "Wrong Password";
        }
    } else {
        throw "User doesn't exist";
    }

    return false;
}

/// @brief Asks for login id, pass
bool Login::ask() {
    std::string id_user;
    std::string pass_user = "";
    char ch;
    std::cout << "Enter Login Id: ";
    std::cin >> id_user;
    std::cout << "Enter Password: ";    
    ch = _getch();
    while(ch != 13 && ch != 8) {    // 13 is enter, 8 is backspace
        pass_user.push_back(ch);
        std::cout << '*';
        ch = _getch();
    }
    std::cout << std::endl;
    try {
        if (authentication(id_user, pass_user)) {
            std::cout << "Login Successful" << std::endl;
            return true;
        }
    } catch (const char* exp) {
        std::cout << "Exception: " << exp;
    }
    return false;
}


// int main() {
//     Login login{};
//     login.ask();
//     std::string id_user;
//     std::string pass_user;
//     std::cout << "Enter Login Id: ";
//     std::cin >> id_user;
//     std::cout << "Enter Password: "; 
//     std::cin >> pass_user;

//     try {
//         if (login.new_user(id_user, pass_user)) {
//             std::cout << "User created" << std::endl;
//         }
//     } catch (const char* exp) {
//         std::cout << "Exception: " << exp;
//     }
// }