#ifndef _FILLUPS_H_
#define _FILLUPS_H_

#include <iostream>
#include <ctime>
#include <string>
#include <array>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>

struct Time {
    int hrs;
    int min;
};

struct Date {
    int day;
    std::string month;
    int year;
    std::string get_mname (int num);
};

class Txn {
    Time tym;
    Date date;
    double fuel;
    long reading;
    double amount;
    double fuel_rate;
    std::string date_str, time_str;
    time_t tt;
    std::map<int, int> logs;

public:
    Txn();
    Txn(double fuel, long reading);
    Txn(std::string date, std::string time, double fuel, long reading);

    // Getters and Setters
    void set_fuel(double fuel);
    void set_reading(long reading);
    void set_amount(double amount);
    void set_fuel_rate(double rate);
    std::string disp_date() const;
    std::string disp_time() const;
    double disp_fuel();
    long disp_reading();

    // Details Method
    void get_stat(const Txn& txn);
    void edit_details(const Txn& txn);

    // File Handling
    std::string to_csv ();

    // Operators/Method Overloading
    friend std::ostream& operator<< (std::ostream &os, const Txn& txn);

    /*  Extra Methods
    double fuel_filled (double amount, double fuel_rate);
    */
};

#endif