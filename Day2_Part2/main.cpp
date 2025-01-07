#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <iterator>

auto readToString(std::string filename) -> std::string  {
    std::ifstream file(filename, std::ios_base::binary | std::ios_base::in);
    using Iterator = std::istreambuf_iterator<char>;
    std::string content(Iterator{file}, Iterator{});
    return content;
}

auto split(const std::string& s, const char delim) -> std::vector<int> {
    std::vector<int> result;
    std::stringstream ss(s);
    std::string item;

    while (getline(ss, item, delim)) {
        result.push_back(std::stoi(item));
    }
    return result;
}

auto main() -> int {
    std::cout << "--- Advent of code 2024 : Day 3 Part 1 ---" << std::endl;

    std::string contentString = readToString("input.txt");
    int muli = 0;
    int total = 0;
    std::string delimiter = ",";

    std::regex regex1("[0-9]{1,3},[0-9]{1,3}");
    std::smatch res;
    while (regex_search(contentString, res, regex1, std::regex_constants::match_any)) {
        std::string s = res[0];
        std::vector<int> numbers = split(s, ',');
        muli = numbers[0]*numbers[1];
        total += muli;
        std::cout << total << std::endl;
        contentString = res.suffix().str();
    }
    std::cout << total << std::endl;

    return 0;
}
