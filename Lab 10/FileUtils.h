#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>

class FileUtils {
public:
    static std::vector<std::string> readLines(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            throw std::runtime_error("Failed to open file: " + filename);
        }

        std::vector<std::string> lines;
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        return lines;
    }

    static void writeLines(const std::string& filename, const std::vector<std::string>& lines) {
        std::ofstream file(filename);
        if (!file) {
            throw std::runtime_error("Failed to create file: " + filename);
        }

        for (const auto& line : lines) {
            file << line << std::endl;
        }
    }

    static bool fileExists(const std::string& filename) {
        std::ifstream file(filename);
        return file.good();
    }

    static long getFileSize(const std::string& filename) {
        std::ifstream file(filename, std::ios::binary | std::ios::ate);
        if (!file) {
            throw std::runtime_error("Failed to open file: " + filename);
        }
        return file.tellg();
    }
};

#endif 