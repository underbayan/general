//
// Created by underbayan on 2017/10/30.
//
#include <iostream>

#define  MAX_LENGTH 30
using namespace std;
int main() {
    unsigned int jacks[MAX_LENGTH];
    size_t index = 0;
    while (std::cin.peek() != '\n' && std::cin >> jacks[index] && ++index < MAX_LENGTH) ;
    cin.ignore();
    while(index-->0){
        cout<<jacks[index];
    }
    return 0;
}