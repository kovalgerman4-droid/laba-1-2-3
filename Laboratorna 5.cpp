#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<sstream>
#include<string>

int append_and_count(std::vector<int>& arr, std::vector<int>& values) {
    for(int val : values) {
        arr.push_back(val);
        
    }
    return arr.size();
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

int main() {
    std::vector<int> arr = get_words<int>();
    std::vector<int> values = get_words<int>();
    int res = append_and_count(arr, values);
    std::cout << res << std::endl;
    return 0;
}
