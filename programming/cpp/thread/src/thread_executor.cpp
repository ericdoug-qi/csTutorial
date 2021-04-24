#include <iostream>
#include <thread>
#include "thread_executor.hpp"



void ThreadExecutor::Main() override
{
    
    std::cout << "ThreadExecutor Main" << std::endl;

    while(!is_exit())
    {
         this_thread::sleep_for(milliseconds(100));
         std::cout << "." << std::flush;
    }
}
