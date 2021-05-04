#ifndef __H_THREAD_BASE_H__

#include <thread>
#include <iostream>
#include <string>


class ThreadBase
{
public:
    std::string name;
    int age = 100;

    // 启动线程
    virtual void Start();

    // 等待线程退出
    virtual void Wait();

    // 设置线程退出标志，并等待
    virtual void Stop();
    
    // 线程是否退出
    bool is_exit();

private:
    std::thread th_;
    bool is_exit_ = false;

    virtual void Main() = 0; // 纯虚函数， 入口线程函数
};

#endif // end of thread base