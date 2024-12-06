#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <ranges>

std::vector<int> split(const std::string &s, char delim) {
    std::vector<int> result;
    std::stringstream ss(s);
    std::string item;

    while (getline(ss, item, delim)) {
        result.push_back(std::stoi(item));
    }
    return result;
}

bool ecart(const std::vector<int>& v) {
    for (int i = 1; i < v.size(); i++) {
        if (std::abs(v[i] - v[i-1]) > 3) {
            std::cout << "false: " << v[i] << "-" << v[i-1] << std::endl;
            std:: cout << std::abs(v[i] - v[i-1]) << std::endl;
            std::cout << " " << std::endl;
            return false;
        }
        std::cout << "true: " << v[i] << "-" << v[i-1] << std::endl;
        std:: cout << std::abs(v[i] - v[i-1]) << std::endl;
        std::cout << " " << std::endl;
        return true;
    }
    return false;
}

auto main() -> int {
    std::cout << "--- Advent of 2024 : Day 2 ---" << std::endl;

    std::string input;
    int safe = 0;

    std::ifstream inputFile("input.txt");
    while (std::getline(inputFile, input)) {
        std::vector<int> fileLine = split(input, ' ');
        if (std::ranges::is_sorted(fileLine)) {
            if (ecart(fileLine)) {
                safe++;
            }
        }
        else if (std::ranges::is_sorted(fileLine, std::greater{})) {
            if (ecart(fileLine)) {
                safe++;
            }
        }
    }
    inputFile.close();
    std::cout << safe << std::endl;
    return 0;
}
