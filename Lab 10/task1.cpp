#include <iostream>
#include "FileUtils.h"

int main() {
    try {
        std::vector<std::string> records = FileUtils::readLines("data_records.txt");
        std::cout << "Total records: " << records.size() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}