#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <ranges>

auto split(const std::string &s, const char delim) -> std::vector<int> {
    std::vector<int> result;
    std::stringstream ss(s);
    std::string item;

    while (getline(ss, item, delim)) {
        result.push_back(std::stoi(item));
    }
    return result;
}

auto ecart(const std::vector<int>& v) -> bool {
    for (int i = 1; i < v.size(); i++) {
        if (std::abs(v[i] - v[i-1]) > 3) {
            return false;
        }
    }
    return true;
}

bool duplicate(std::vector<int>& v) {
        std::ranges::sort(v);
        return std::ranges::adjacent_find(v) != v.end();
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
                if (duplicate(fileLine)) {
                } else {
                    safe++;
                }
            }
        }
        else if (std::ranges::is_sorted(fileLine, std::greater{})) {
            if (ecart(fileLine)) {
                if (duplicate(fileLine)) {
                } else {
                    safe++;
                }
            }
        }
    }
    inputFile.close();
    std::cout << safe << std::endl;
    return 0;
}
