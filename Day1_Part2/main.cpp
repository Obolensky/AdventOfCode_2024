#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

auto main() -> int {
    std::cout << "--- Advent of 2024 : Day 1 ---" << std::endl;

    std::vector<int> arr1;
    std::vector<int> arr2;
    std::string input;

    std::ifstream inputFile("input.txt");
    while (std::getline(inputFile, input)) {
        arr1.push_back(std::stoi(input.substr(0, input.find("   "))));
        arr2.push_back(std::stoi(input.substr(input.find("   ")+3, input.find('\n'))));
    }
    inputFile.close();

    int res = 0;
    for (int i : arr1) {
        int occurences = 0;
        int total = 0;
        for (int j : arr2) {
            if (i == j) {
                occurences++;
            }
        }
        total = i * occurences;
        res += total;
    }
    std::cout << res << std::endl;

    return 0;
}
