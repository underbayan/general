#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main (int argc, char *argv[])
{
    int tmp[10]={1,2,3,4,5,6,7,8,9,10};
    std::cout<<tmp[-5]<<"---------";
    int a=10;

    int * p=&a;
    int * b=p;
    int * m=new int(1);
    cout<<*p<<"---"<<*b<<endl;

    return 0;
}
