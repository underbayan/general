//
// Created by waylens on 2018/2/1.
//

#include <list>
#include <mutex>
#include <algorithm>
#include <iostream>
#include <thread>

using namespace std;

std::list<int> some_list;    // 1
std::mutex some_mutex;    // 2

void add_to_list(int new_value) {
    std::lock_guard<std::mutex> guard(some_mutex);
    cout << "inset_back:" << new_value << endl;
    some_list.push_back(new_value);
}

void pop_list_front(int num) {
    std::lock_guard<std::mutex> guard(some_mutex);
    if (some_list.size()) {
        cout << num << " pop_front:" << some_list.front() << endl;
        some_list.pop_front();
    } else {
        cout << "empty list!!"<<endl;
    }
}

bool pop_list_back(int num) {
    std::lock_guard<std::mutex> guard(some_mutex);
    if (some_list.size()) {
        cout << num << " pop_back:" << some_list.back() << endl;
        some_list.pop_back();
    } else {
        cout << "empty list!!"<<endl;
    }

}

int main() {
    int num = 1000;
    while (num--) {
        std::thread t1(add_to_list, 1);
        std::thread t4(add_to_list, 2);
        std::thread t2(pop_list_front, num);
        std::thread t3(pop_list_back, num);
        std::cout << "\nCurrent list:";
        for (auto v : some_list) { std::cout << v << ","; }
        std::cout << endl;
        t1.join();
        t2.join();
        t3.join();
        t4.join();
    }
}