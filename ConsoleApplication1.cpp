// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<concepts>
using namespace std;
template<typename T>
requires std::floating_point<T> 
void print(T a, T b) { cout<< a + b; }

template <typename T>
concept Printable = requires(T value)
{
    cout << value << endl;
};


template <Printable T> 
void print(T value)
{
    cout << "The printable value is: " << value << endl;
}


int main()
{
    //print(10,90);
    print(190);
    std::cout << "Hello World!\n";
}

