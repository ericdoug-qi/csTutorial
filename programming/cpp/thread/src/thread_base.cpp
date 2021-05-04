#include "thread_base.hpp"

void ThreadBase::Start()
{
    is_exit_ = false;
    std::cout << "ThreadBase " << name << ":" << age << std::endl;
    th_ = std::thread(&ThreadBase::Main, this);
}

void ThreadBase::Wait()
{
    if (th_.joinable())
    {
        th_.join();
    }
}

// 设置线程退出标志，并等待
void ThreadBase::Stop()
{
    is_exit_ = true;
    Wait();
}

bool ThreadBase::is_exit()
{
    return is_exit_;
}