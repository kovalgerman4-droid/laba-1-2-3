
#include<iostream>
#include<algorithm>
#include<iterator>
#include<limits>
#include<sstream>
#include<string>
#include<vector>

int linear_search(std::vector<int> &arr, int target) {
    for(size_t i = 0; i < arr.size(); ++i) {
        if(arr[i] == target)
            return i;
    }
    return -1;
}

template<typename T>
std::vector<T> get_words(){
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    ss >> std::boolalpha;
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

void ignore_line() {

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<int> arr = get_words<int>();
    int target;
    std::cin >> target;
    ignore_line();
    int res = linear_search(arr, target);
    std::cout << res << '\n';
    return 0;
}
