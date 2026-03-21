#include <iostream>
#include <string>
#include <limits>

std::string safe_modify_string(std::string& s, int index, std::string& new_char) {
    if (index < 0 || index >= s.length()) return s;
    if (new_char.length() != 1) return s;
    std::string result = s;
    result[index] = new_char[0];
    return result;
}
void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
int main() {
    std::string s;
    std::cout << "pleasee name the string : ";
    std::getline(std::cin, s);
    int index;
    std::cout << " pleasee the index : ";
    std::cin >> index;
    ignore_line();
    std::string new_char;
    std::cout << " Pleasee THe new char : ";
    std::getline(std::cin, new_char);
    std::string result = safe_modify_string(s, index, new_char);
    std::cout << result << '\n';
    return 0;
}