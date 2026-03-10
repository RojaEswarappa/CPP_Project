// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<thread>
#include<future>
#include<mutex>
#include<atomic>
using namespace std;
atomic<int>counter(0);
static int data = 0;
mutex m;
int add()
{
    return ::data;
}
void fun()
{
    //m.lock();
  //  lock_guard<mutex>l(m);
    for (int i = 0; i < 10; i++)
    {
        counter++;
        ::data++;
    }
   // m.unlock();
    cout << ::data;
}
int main()
{
    thread t1(fun);
  
    thread t2(fun);
    t1.join();
    t2.join();

    future<int>res = async(add);
  cout<<  res.get();
    std::cout << "Hello World!\n";
    cout << counter;
}


