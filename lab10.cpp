#include<algorithm>
#include<iostream>
#include<vector>
#include<iterator>
#include<string>
#include<sstream>
#include<limits>

template<typename T>
struct Node{
    T val;
    Node* next;
    explicit Node(T val, Node<T>* next = nullptr) : val{val}, next{next}{}

    ~Node(){
        delete next;
    }
};
Node<int>* insert_at_tail(Node<int>* head, int value){
    if(head == nullptr){
        return new Node<int>(value);
    }
    Node<int>* current = head;
    while(current->next != nullptr){
        current = current->next;
    }
    current->next = new Node<int>(value);
    return head;
    
}

template<typename Iterator, typename Converter, typename T>
Node<T>* build_list(Iterator begin, Iterator end, Converter converter){
    Node<T>* head = nullptr;
    for(auto it = begin; it != end; ++it){
        head = insert_at_tail(head, converter(*it));
    }
    return head;
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
void ignore_line(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}
template<typename T>
void put_words(const std::vector<T>& v){
    if(!v.empty()){
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

template<typename T, typename Converter>
void format_list(Node<T>* head, Converter converter, std::vector<std::string>& result){
    while(head != nullptr){
        result.push_back(converter(head->val));
        head = head->next;
    }
}

int main(){
    std::vector<std::string> head_vec = get_words<std::string>();
    auto head_it = head_vec.begin();
    auto head_end = head_vec.end();
    Node<int>* head = build_list<std::vector<std::string>::iterator, decltype([](auto s){ return std::stoi(s); }), int>(head_it, head_end, [](auto s){ return std::stoi(s); });
    int value;
    std::cin >> value;
    ignore_line();
    Node<int>* res = insert_at_tail(head, value);
    std::vector<std::string> res_vec;
    format_list(res, [](auto v){ return std::to_string(v);}, res_vec);
    put_words(res_vec);
    return 0; 
}
