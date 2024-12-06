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

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int distance = 0;
    for (int i = 0; i < arr1.size(); i++) {
        distance += std::abs(arr1[i] - arr2[i]);
    }

    std::cout << distance << std::endl;

    return 0;
}
