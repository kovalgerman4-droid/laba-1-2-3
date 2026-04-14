#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <queue>
#include <string>
#include <utility>
#include <vector>

std::queue<int> execute(std::vector<std::string>& program) {
    std::queue<int> q;
    for (const std::string& cmd : program) {
        if (cmd == "pop") {
            if (q.empty()) {
                std::cout << "Queue is empty!" << std::endl;
            } else {
                q.pop();
            }
        } else if (cmd == "peek") {
            if (q.empty()) {
                std::cout << "Queue is empty!" << std::endl;
            } else {
                std::cout << q.front() << std::endl;
            }
        } else if (cmd.size() >= 6 && cmd.substr(0, 5) == "push ") {
            std::string num_str = cmd.substr(5);
            int x = std::stoi(num_str);
            q.push(x);
        }
    }
    return q;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    int program_length;
    std::cin >> program_length;
    ignore_line();
    std::vector<std::string> program;
    for (int i = 0; i < program_length; i++) {
        std::string line;
        std::getline(std::cin, line);
        program.emplace_back(std::move(line));
    }
    std::queue<int> res = execute(program);
    // create a vector out of the queue
    std::vector<int> res_vec;
    while (!res.empty()) {
        res_vec.emplace_back(res.front());
        res.pop();
    }
    put_words(res_vec);
}
