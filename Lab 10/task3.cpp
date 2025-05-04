#include <iostream>
#include <algorithm>
#include "FileUtils.h"

int main() {
    try {
        std::vector<std::string> logLines = FileUtils::readLines("large_log.txt");
        
        std::sort(logLines.begin(), logLines.end());
        
        FileUtils::writeLines("sorted_log.txt", logLines);
        
        std::cout << "Log sorted successfully. Total lines: " << logLines.size() << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}