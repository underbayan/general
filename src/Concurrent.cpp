//
// Created by waylens on 2018/1/30.
//
#include <iostream>
#include <thread>

using namespace std;

void hello() { std::cout << "Hello Concurrent World\n"; }

class background_task {
public:
    void operator()() const { std::cout << "This simple thread class instance \n"; }
};


int main() {
    std::thread t(hello);
    background_task f;
    std::thread my_thread(f);
    //std::thread my_thread(background_task()); // this is wrong way to create a thread
    std::thread my_thread1((background_task()));  // 1
    std::thread my_thread2{background_task()};    // 2
    std::thread my_thread3([] { std::cout << "This simple thread from lamada function \n"; });
    t.join();
    my_thread.join();
    my_thread1.join();
    my_thread2.join();
    my_thread3.join();

    //---------------------- split line ----------------------------
    struct func {
        int &i;

        func(int &i_) : i(i_) { }

        void operator()() {
            for (unsigned j = 0; j < 10000000; j++) {
                cout << i++;
            }
        }
    };
    int local_count = 0;
    func my_func(local_count);
    std::thread my_thread4(my_func);
    // this will random to generate the number length ,for the quote will disapear when the loop is not end
    my_thread4.detach();
//    assert(!my_thread4.joinable());
}