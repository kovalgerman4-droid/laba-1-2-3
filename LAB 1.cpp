#include <iostream>
#include <string>
#include <algorithm>

int compare_strings(std::string& s1, std::string& s2) {
    int n = std::min(s1.length(), s2.length());
    for (int i = 0; i < n; i++) {
        if (s1[i] < s2[i]) return -1;
        if (s1[i] > s2[i]) return 1;
    }
        if (s1.length() < s2.length()) return -1;
        if (s1.length() > s2.length()) return 1;
    return 0;
}
int main() {
    std::string s1,s2;
    std::cout << " please i want know the first string : ";
    getline(std::cin, s1);
    std::cout << " please I want Look the second string : ";
    getline(std::cin, s2);
    int res = compare_strings(s1, s2);
    std::cout << res << '\n';
    return 0 ;
}

