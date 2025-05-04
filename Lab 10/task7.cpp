#include <iostream>
#include <vector>
#include <algorithm>
#include "FileUtils.h"
#include "StringUtils.h"

struct ConfigItem {
    std::string key;
    std::string value;
};

int main() {
    try {
        std::vector<std::string> configLines = FileUtils::readLines("config.txt");
        std::vector<ConfigItem> configItems;
        
        for (const auto& line : configLines) {
            size_t pos = line.find('=');
            if (pos != std::string::npos) {
                std::string key = line.substr(0, pos);
                std::string value = line.substr(pos + 1);
                configItems.push_back({key, value});
            }
        }
        
        std::sort(configItems.begin(), configItems.end(), 
            [](const ConfigItem& a, const ConfigItem& b) {
                return a.key < b.key;
            });
        
        std::vector<std::string> sortedConfig;
        for (const auto& item : configItems) {
            sortedConfig.push_back(item.key + "=" + item.value);
        }
        
        FileUtils::writeLines("sorted_config.txt", sortedConfig);
        
        std::cout << "Config sorted successfully. Total items: " << configItems.size() << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}