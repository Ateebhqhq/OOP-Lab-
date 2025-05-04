#include <iostream>
#include <vector>
#include "FileUtils.h"
#include "StringUtils.h"

int main() {
    try {
        std::vector<std::string> logLines = FileUtils::readLines("large_log.txt");
        std::vector<std::string> errorLines;
        
        for (const auto& line : logLines) {
            if (line.find("ERROR:") != std::string::npos) {
               
                size_t pos = line.find("ERROR:") + 7;
                std::string errorMsg = line.substr(pos);
                errorLines.push_back(errorMsg);
            }
        }
        
        FileUtils::writeLines("error_log.txt", errorLines);
        
        std::cout << "Error extraction complete. Found " << errorLines.size() 
                  << " errors and saved to error_log.txt" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}