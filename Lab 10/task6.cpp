#include <iostream>
#include <map>
#include <iomanip>
#include "FileUtils.h"
#include "StringUtils.h"

struct VehicleStats {
    int count = 0;
    double totalFuel = 0.0;
};

int main() {
    try {
        std::vector<std::string> vehicleData = FileUtils::readLines("vehicle.txt");
        std::map<std::string, VehicleStats> vehicleStats;
        
        for (const auto& line : vehicleData) {
            auto parts = StringUtils::split(line, ' ');
            if (parts.size() == 2) {
                std::string vehicleType = parts[0];
                double fuelConsumption = std::stod(parts[1]);
                
                vehicleStats[vehicleType].count++;
                vehicleStats[vehicleType].totalFuel += fuelConsumption;
            }
        }
        
        std::cout << "Vehicle Fuel Consumption Report" << std::endl;
        std::cout << "===============================" << std::endl;
        std::cout << std::left << std::setw(10) << "Type" 
                  << std::right << std::setw(8) << "Count" 
                  << std::right << std::setw(15) << "Avg Fuel (L)" << std::endl;
        std::cout << "-------------------------------" << std::endl;
        
        for (const auto& [type, stats] : vehicleStats) {
            double avgFuel = stats.count > 0 ? stats.totalFuel / stats.count : 0;
            std::cout << std::left << std::setw(10) << type 
                      << std::right << std::setw(8) << stats.count 
                      << std::right << std::setw(15) << std::fixed << std::setprecision(2) << avgFuel << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}