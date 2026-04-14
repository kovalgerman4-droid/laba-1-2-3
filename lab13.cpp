#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <utility>
#include <vector>

std::vector<std::string> process_tasks_fifo(std::vector<std::string>& tasks) {
    std::queue<std::string> q;
    for (const auto& task : tasks) {
        q.push(task);
    }
    std::vector<std::string> result;
    result.reserve(tasks.size());
    while (!q.empty()) {
        result.push_back(q.front());
        q.pop();
    }
    return result;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int tasks_length;
    std::cin >> tasks_length;
    ignore_line();
    std::vector<std::string> tasks;
    for (int i = 0; i < tasks_length; i++) {
        std::string line;
        std::getline(std::cin, line);
        tasks.emplace_back(std::move(line));
    }
    std::vector<std::string> res = process_tasks_fifo(tasks);
    for (const std::string& line : res) {
        std::cout << line << '\n';
    }
}
