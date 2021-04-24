#include <iostream>
#include <thread>
#include "thread_executor.hpp"



void ThreadExecutor::Main() override
{
    
    std::cout << "ThreadExecutor Main" << std::endl;

    while(!is_exit())
    {
         std::this_thread::sleep_for(std::chrono::milliseconds(100));
         std::cout << "." << std::flush;
    }
}
