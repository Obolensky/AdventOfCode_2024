#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <iterator>

auto readToString(const std::string& filename) -> std::string  {
    std::ifstream file(filename, std::ios_base::binary | std::ios_base::in);
    using Iterator = std::istreambuf_iterator<char>;
    std::string content(Iterator{file}, Iterator{});
    return content;
}

auto main() -> int {
    std::cout << "--- Advent of code 2024 : Day 3 Part 1 ---" << std::endl;

    std::string contentString = readToString("input.txt");
    int total = 0;
    std::regex regex1("mul\\([0-9]{1,3},[0-9]{1,3}\\)");
    std::smatch res;
    while (regex_search(contentString, res, regex1, std::regex_constants::match_any)) {
        std::string s = res[0];
        
        // get 1st number
        unsigned first = s.find('(');
        unsigned last = s.find_last_of(',');
        const int num1 = stoi(s.substr(first+1,last-first-1));
        // get 2nd number
        first = s.find(',');
        last = s.find_last_of(')');
        const int num2 = stoi(s.substr(first+1,last-first-1));
        
        total += num1*num2;
        contentString = res.suffix().str();
    }
    std::cout << total << std::endl;

    return 0;
}
