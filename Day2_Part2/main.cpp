#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <ranges>

auto split(const std::string& s, const char delim) -> std::vector<int> {
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
        if (v[i] - v[i - 1] > 3 || v[i] - v[i - 1] < -3) {
            return false;
        }
    }
    return true;
}

auto duplicate(std::vector<int>& v) -> bool {
    std::ranges::sort(v);
    return std::ranges::adjacent_find(v) != v.end();
}

auto mainLoop(std::vector<int>& v) -> bool {
    if (std::ranges::is_sorted(v) || std::ranges::is_sorted(v, std::greater{})) {
        if (ecart(v)) {
            if (!duplicate(v)) {
                return true;
            }
        }
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
        if (mainLoop(fileLine)) {
            safe++;
        }
        else {
            // A tester si ca decalle bien quand on insert dans le vector
            for (int i = 0; i < fileLine.size(); i++) {
                int temp = fileLine[i];
                fileLine.erase(fileLine.begin() + i);
                if (mainLoop(fileLine)) {
                    safe++;
                    break;
                }
                fileLine.insert(fileLine.begin() + i, temp);
            }
        }
    }
    inputFile.close();
    std::cout << safe << std::endl;

    return 0;
}
