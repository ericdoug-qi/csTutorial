#ifndef __H_THREAD_EXECUTOR_H__
#include "thread_base.hpp"

class ThreadExecutor:public ThreadBase
{
public:
    void Main()
    {
        cout << "ThreadExecutor Main" << endl;
    }
};
#endif