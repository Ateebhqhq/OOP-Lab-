#include <iostream>
#include <numeric>
#include "FileUtils.h"
#include "StringUtils.h"

struct Expense {
    std::string date;
    std::string category;
    double amount;
};

int main() {
    try {
        std::vector<std::string> lines = FileUtils::readLines("data_records.txt");
        std::vector<Expense> expenses;
        
        for (const auto& line : lines) {
            auto parts = StringUtils::split(line, ',');
            if (parts.size() == 3) {
                Expense expense;
                expense.date = parts[0];
                expense.category = parts[1];
                expense.amount = std::stod(parts[2]);
                expenses.push_back(expense);
            }
        }
        
        double totalAmount = std::accumulate(expenses.begin(), expenses.end(), 0.0,
            [](double sum, const Expense& expense) {
                return sum + expense.amount;
            });
        
        double averageAmount = expenses.empty() ? 0.0 : totalAmount / expenses.size();
        
        std::cout << "Average expense amount: $" << averageAmount << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
