#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

std::unordered_map<std::string, int> count_characters(std::string& s){
    std::unordered_map<std::string, int> freq;
    for (char c : s) {
        std::string key(1, c);
        freq[key]++;
    }
    return freq;
}
int main() {
    std::string s;
    std::getline(std::cin, s);
    std::unordered_map<std::string, int> res = count_characters(s);
    std::map<std::string, int> ordered_res(res.begin(), res.end());
    for (auto const& [key, val] : ordered_res){
        std::cout << key << ": " << val << '\n';
    }

}