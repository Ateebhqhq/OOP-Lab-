#include <iostream>
#include <map>
#include "FileUtils.h"
#include "StringUtils.h"

int main() {
    try {
        std::vector<std::string> logLines = FileUtils::readLines("sensor_log.txt");
        std::map<std::string, int> sensorCounts;
        
        for (const auto& line : logLines) {
            std::vector<std::string> parts = StringUtils::split(line, ' ');
            if (parts.size() >= 2) {
                std::string sensorId = parts[1]; 
                sensorCounts[sensorId]++;
            }
        }
        
        std::cout << "Sensor Reading Counts:" << std::endl;
        std::cout << "--------------------" << std::endl;
        for (const auto& [sensor, count] : sensorCounts) {
            std::cout << sensor << ": " << count << " readings" << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}