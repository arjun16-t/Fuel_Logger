#include <iostream>
#include <conio.h>
#include "login.h"
#include "fillups.h"
#include "file_handling.h"

void title_border(std::string title, int total_width = 70) {
    std::cout << std::endl;
    std::cout << std::setw(total_width) << std::setfill('=') << "" << std::endl;
    std::cout << std::setw(total_width - title.length() - 2) << std::setfill(' ') << std::right << title << std::endl;
    std::cout << std::setw(total_width) << std::setfill('=') << "" << std::endl;
}

bool login_info() {
    /*
    WELCOME USER
    Ask for Login Id and Pass
    Display Menu
    */

    std::string title{"WELCOME TO FUEL LOGGER"};
    title_border(title);    
    
    Login login {"admin", "admin"};
    std::string id, pass;
    std::cout << "Enter User ID: ";
    std::cin >> id;
    std::cout << "Enter Password: ";
    std::cin >> pass;

    if (!login.authentication(id, pass)) {
        std::cout << "Invalid ID or Pass" << std::endl;
        return false;
    }
    std::cout << "Login Successful";    
    return true;
}

bool write_to_file(Txn txn) {
    std::string filepath {"logs.csv"};
    Log log {filepath};
    try {
        log.set_record(txn);
        return true;
    } catch (const std::runtime_error &e) {
        std::cout << "Error Encountered: " << e.what() << std::endl;
    }
}

void read_from_file() {
    std::string filepath {"logs.csv"};
    Log log {filepath};
    try {
        std::map<std::string, Txn> temp = log.get_record();
        std::map<std::string, Txn>::iterator it = temp.begin();
        while (it != temp.end()) {
            std::cout << it->first << " " << it->second.disp_time() << " "
            << it->second.disp_fuel() << " " << it->second.disp_reading() << std::endl;
            it++;
        }
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void fillup_details() {
    std::string title{"ADD NEW FILL UP ENTRY"};
    title_border(title);

    Txn txn;

    std::cout << "Fillup Date: " << txn.disp_date() << std::endl;
    std::cout << "Fillup Time: " << txn.disp_time() << std::endl;
    
    int ch;
    std::cout << "Fuel (in L) or Fuel (in Rs.) -- (1/2): ";
    std::cin >> ch;
    if (ch == 1) {
        double fuel;
        std::cout << "Fuel (in L): ";
        std::cin >> fuel;
        txn.set_fuel(fuel);
    } else if (ch == 2) {
        double rate, amount;
        std::cout << "Fuel Rate ( Rs/L): ";
        std::cin >> rate;
        std::cout << "Amount (in Rs.): ";
        std::cin >> amount;
        txn.set_fuel_rate(rate);
        txn.set_amount(amount);
    } else {
        std::cerr << "Invalid Choide";
    }
    long reading;
    std::cout << "Odometer Reading: ";
    std::cin >> reading;
    txn.set_reading(reading);

    system("cls");
    txn.get_stat(txn);
}


int main() {
    // if (login_info()) {
    //     system("cls");
    //     fillup_details();

    // }

    read_from_file();
    return 0;
}