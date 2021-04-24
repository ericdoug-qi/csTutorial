#ifndef __H_THREAD_BASE_H__

#include <thread>
#include <iostream>
#include <string>

using namespace std;

class ThreadBase
{
public:
    virtual void Start(){
        cout << "MyThread Main " << name << ":" << age << endl;
        th_ = std::thread(ThreadBase::Main, this);
    }

    string name;
    int age = 100;
private:
    std::thread th_;

    virtual void Main() = 0; // 纯虚函数， 入口线程函数
};

#endif // end of thread base