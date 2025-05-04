#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include "FileUtils.h"
#include "StringUtils.h"

std::string cleanWord(const std::string& word) {
    std::string cleaned;
    for (char c : word) {
        if (std::isalpha(c)) {
            cleaned += std::tolower(c);
        }
    }
    return cleaned;
}

int main() {
    try {
        std::vector<std::string> logLines = FileUtils::readLines("large_log.txt");
        std::map<std::string, int> wordFrequency;
        
        for (const auto& line : logLines) {
            std::vector<std::string> words = StringUtils::split(line, ' ');
            
            for (const auto& word : words) {
                std::string cleanedWord = cleanWord(word);
                if (!cleanedWord.empty()) {
                    wordFrequency[cleanedWord]++;
                }
            }
        }
        
        std::vector<std::pair<std::string, int>> wordFreqPairs(
            wordFrequency.begin(), wordFrequency.end());
        
        std::sort(wordFreqPairs.begin(), wordFreqPairs.end(),
            [](const auto& a, const auto& b) {
                return a.second > b.second;
            });
        
        const int topCount = std::min(10, static_cast<int>(wordFreqPairs.size()));
        
        std::cout << "Top " << topCount << " Most Frequent Words" << std::endl;
        std::cout << "==========================" << std::endl;
        std::cout << std::left << std::setw(15) << "Word" 
                  << std::right << std::setw(10) << "Frequency" << std::endl;
        std::cout << "--------------------------" << std::endl;
        
        for (int i = 0; i < topCount; i++) {
            const auto& [word, freq] = wordFreqPairs[i];
            std::cout << std::left << std::setw(15) << word 
                      << std::right << std::setw(10) << freq << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}