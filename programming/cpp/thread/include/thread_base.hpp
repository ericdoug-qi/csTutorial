#ifndef __H_THREAD_BASE_H__

#include <thread>
#include <iostream>
#include <string>


class ThreadBase
{
public:
    string name;
    int age = 100;


    virtual void Start()
    {
        is_exit_ = false;
        std::cout << "MyThread Main " << name << ":" << age << std::endl;
        th_ = std::thread(&ThreadBase::Main, this);
    }

    virtual void Wait() 
    {
        if (th_.joinable()) {
            th_.join();
        }
    }

    virtual void Stop()
    {
        is_exit_ = true;
        Wait();
         
    }

    bool is_exit() {
        return is_exit_;
    }
private:
    std::thread th_;
    bool is_exit_ = false;

    virtual void Main() = 0; // 纯虚函数， 入口线程函数
};

#endif // end of thread base