

#include <iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;
condition_variable cv;
bool ready = false;
mutex m;
void reader()
{
    unique_lock<mutex>ul(m);
   
    
    cv.wait(ul, [] { return ready; });
        cout << "reader is ready\n";
    
}
void writer()
{
    lock_guard<mutex>l(m);
    ready = true;
    cv.notify_one();
    cout << "writer is ready\n";

}

int main()
{
    thread t1(reader);
    thread t2(writer);
    t1.join();
    t2.join();

    std::cout << "Hello World!\n";
}

