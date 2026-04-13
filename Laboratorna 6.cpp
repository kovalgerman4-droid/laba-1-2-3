#include<iostream>
#include<algorithm>
#include<iterator>
#include<limits>
#include<sstream>
#include<string>
#include<vector>

std::vector<int>
insert_at_position(std::vector<int>& arr, int index, int value) {
    arr.insert(arr.begin() + index, value);
    return arr;
}
template<typename T>
std::vector<T> get_words(){
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    ss >> std::boolalpha;
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss},
    std::istream_iterator<T>{},
    std::back_inserter(v));
    return v;
}
void ignore_line() {

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back() << '\n';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> arr = get_words<int>();
    int index;
    std::cin >> index;
    ignore_line();
    int value;
    std::cin >> value;
    ignore_line();
    std::vector<int> res = insert_at_position(arr, index, value);
    put_words(res);
    return 0;
}
