#ifndef __H_THREAD_EXECUTOR_H__
#include "thread_base.hpp"

class ThreadExecutor: public ThreadBase
{
public:
    void Main() override
    {

        std::cout << "ThreadExecutor Main" << std::endl;

        while (!is_exit())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::cout << "." << std::flush;
        }
    }
};
#endif