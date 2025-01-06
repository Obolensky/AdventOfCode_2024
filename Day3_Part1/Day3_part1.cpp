#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <iterator>

std::string readToString(std::string filename) {
    std::ifstream file(filename, std::ios_base::binary | std::ios_base::in);
    using Iterator = std::istreambuf_iterator<char>;
    std::string content(Iterator{file}, Iterator{});
    return content;
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
        std::string token1 = s.substr(0, s.find(delimiter));
        std::string token2 = s.substr(1, s.find(delimiter));
        token2 = token2.substr(0, token2.size()-1);
        std::cout << token2 << std::endl;
        /**
        muli = stoi(token1) * stoi(token2);
        total += muli;
        **/
        contentString = res.suffix().str();
    }
    std::cout << total << std::endl;

    return 0;
}
