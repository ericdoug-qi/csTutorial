#include <iostream>
#include <future>
#include <string>

using namespace std;


void TestFuture(promise<string> p) 
{
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "Begin set value" << endl;
    p.set_value("TestFuture value");
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "end of test future" << endl;

}

int main(int argc, char* argv[])
{
    // 异步传输变量存储
    promise<string> p;

    // 用来获取线程异步值获取
    auto future = p.get_future();

    auto th = thread(TestFuture, move(p));

    cout << "future get() = " << future.get() << endl;

    th.join();
     

    return 0;
}