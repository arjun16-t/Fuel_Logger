#include "fillups.h"
/// @brief Returns the month_name acc to num
/// @param num 
/// @return Month Name
std::string Date::get_mname(int num) {
    std::string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
                            "Aug", "Sep", "Oct", "Nov", "Dec"};

    return months[num];
}

/// @brief Constructor - initialises fuel, reading, time and date
Txn::Txn() 
: fuel{0.0}, reading{0} {
    struct tm* ti;
    time(&tt);
    ti = localtime(&tt);

    tym.hrs = ti->tm_hour;
    tym.min = ti->tm_min;

    date.day = ti->tm_mday;
    date.month = date.get_mname(ti->tm_mon);
    date.year = ti->tm_year + 1900;             // + 1900 because year starts from 1900

    std::ostringstream dss;
    dss << tym.hrs << ":" << tym.min;
    date_str = dss.str();

    std::ostringstream tss;
    tss << date.day << " " << date.month << ", " << date.year;
    time_str = tss.str();
}

/// @brief Overloaded Constructor
/// @param fuel 
/// @param reading 
Txn::Txn(double fuel, long reading) 
: fuel{fuel}, reading{reading} {
    Txn();
}

Txn::Txn(std::string date, std::string time, double fuel, long reading)
: fuel{fuel}, reading{reading}, date_str {date}, time_str{time} {}

/// @brief Sets fuel (in L)
/// @param fuel 
void Txn::set_fuel(double fuel) {
    this->fuel = fuel;
}

/// @brief Sets odometer reading
/// @param reading 
void Txn::set_reading(long reading) {
    this->reading = reading;
}

/// @brief Sets amount of fuel
/// @param amount 
void Txn::set_amount(double amount) {
    this->amount = amount;
}

/// @brief Sets fuel rate per L
/// @param rate 
void Txn::set_fuel_rate(double rate) {
    this->fuel_rate = rate;
}

/// @brief Displays current time
/// @return Time (hrs and mins)
std::string Txn::disp_time() const{
    return time_str;
}

/// @brief Displays current date
/// @return Date (D/M/Y)
std::string Txn::disp_date() const {
    return date_str;
}

/// @brief Display Fuel
/// @return Fuel (in L)
double Txn::disp_fuel() {
    if (!fuel)
        set_fuel(amount/fuel_rate);
    return fuel;
}

/// @brief Display Odometer Reading
/// @return Odometer Reading
long Txn::disp_reading() {
    return reading;
}

/// @brief Displays summary of current reading
/// @param txn 
void Txn::get_stat(const Txn& txn) {
    std::cout << std::endl;
    std::cout << std::setw(68) << std::setfill('*') << "" << std::endl;
	std::cout << std::setfill(' ');
    std::cout << std::setw(17) << std::left << " Date"
              << std::setw(17) << std::left << "Time"
              << std::setw(17) << std::left << "Fuel (in L)"
              << std::setw(17) << std::left << "Odometer Reading" << std::endl;
    std::cout << std::setw(68) << std::setfill('*') << "" << std::endl;
	std::cout << std::setfill(' ');
    std::cout << txn;
}

/// @brief To edit details (Fuel/ Reading)
/// @param txn 
void Txn::edit_details(const Txn& txn) {  
    char ch;
    do {
        std::cout << "Is this ok? (Y/N): ";
        std::cin >> ch;
        if (ch == 'Y' || ch == 'y')
            std::cout << "Successfully Stored" << std::endl;
        else if (ch == 'N' || ch == 'n') {
            int ch2;
            std::cout << "What would you like to edit?" << std::endl;
            std::cout << "1. Fuel (in L)\n" << "2. Odometer Reading" << std::endl;
            std::cin >> ch2;

            if (ch2 == 1) {
                double fuel;
                std::cout << "Fuel (in L): ";
                std::cin >> fuel;
                set_fuel(fuel);
            } else if (ch2 == 2) {
                long reading;
                std::cout << "Odometer Reading: ";
                std::cin >> reading;
                set_reading(reading);
            } else {
                std::cerr << "Invalid Choice" << std::endl;
            }
            get_stat(txn);
        } else {
            std::cerr << "Invalid Choice" << std::endl;
        }
        
    } while (ch == 'Y' || ch == 'y');
}

/// @brief Output stream operator for class
/// @param os 
/// @param txn 
/// @return Output Stream
std::ostream& operator<< (std::ostream &os, const Txn& txn) {
    os << txn.disp_date() << "|"
        << txn.disp_time() << "|"
        << txn.fuel << "|"
        << txn.reading << std::endl;
    return os;
}

// std::ostream& operator<< (std::ostream &os, const Txn& txn) {
//     os << std::setw(17) << std::left << txn.disp_date()
//         << std::setw(17) << std::left << txn.disp_time()
//         << std::setw(17) << std::left << txn.fuel
//         << std::setw(17) << std::left << txn.reading << std::endl;
//     return os;
// }

