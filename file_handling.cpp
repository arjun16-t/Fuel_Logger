#include "file_handling.h"

bool Log::set_record(std::string filepath, Txn txn) {
    fout.open(filepath, std::ios::app);
    if (!fout) {
        std::cerr << "Error Opening File" << std::endl;
        throw std::runtime_error("File Open Error");
        return false;
    }
    fout << txn;
    fout.close();
    return true;
}

std::map<std::string, Txn> Log::get_record(std::string filepath) {
    std::map<std::string, Txn> temp;

    fin.open(filepath, std::ios::in);
    if (!fin) {
        std::cerr << "Error Opening File" << std::endl;
        throw std::runtime_error("File Open Error");
        return temp;
    }

    std::string line;
    std::getline(fin, line);

    while(getline(fin, line)) {
        std::stringstream ss(line);
        std::string date, time, fuel_str, reading_str;
        double fuel = 0.0;
        long reading = 0;

        if (getline(ss, date, '|') &&
            getline(ss, time, '|') &&
            getline(ss, fuel_str, '|') &&
            getline(ss, reading_str, '|')) {
            try {
                fuel = stod(fuel_str);
                reading = stol(reading_str);
            } catch (const std::exception& e) {
                std::cerr << "Error: Invalid data format in line: " << line << std::endl;
                continue;
            }
            Txn txn {date, time, fuel, reading};
            temp[date] = txn;
        } else {
            std::cerr << "Error: Mal formed line: " << line << std::endl;
        }

        return temp;
    }
}