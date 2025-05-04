#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "FileUtils.h"
#include "StringUtils.h"

struct SensorReading {
    std::string timestamp;
    std::string sensorId;
    double value;
};

int main() {
    try {
        std::vector<std::string> sensorLines = FileUtils::readLines("sensor_log.txt");
        std::vector<SensorReading> readings;
        
        for (const auto& line : sensorLines) {
            auto parts = StringUtils::split(line, ' ');
            if (parts.size() >= 3) {
                SensorReading reading;
                reading.timestamp = parts[0];
                reading.sensorId = parts[1];
                reading.value = std::stod(parts[2]);
                readings.push_back(reading);
            }
        }
        
        std::sort(readings.begin(), readings.end(), 
            [](const SensorReading& a, const SensorReading& b) {
                return a.value > b.value;
            });
        
        const int topCount = std::min(5, static_cast<int>(readings.size()));
        
        std::cout << "Top " << topCount << " Highest Sensor Readings" << std::endl;
        std::cout << "=============================" << std::endl;
        std::cout << std::left << std::setw(25) << "Timestamp" 
                  << std::left << std::setw(10) << "Sensor" 
                  << std::right << std::setw(10) << "Value" << std::endl;
        std::cout << "-----------------------------" << std::endl;
        
        for (int i = 0; i < topCount; i++) {
            const auto& reading = readings[i];
            std::cout << std::left << std::setw(25) << reading.timestamp 
                      << std::left << std::setw(10) << reading.sensorId 
                      << std::right << std::setw(10) << std::fixed << std::setprecision(2) << reading.value << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}