#include <iostream>
#include <mutex>

std::timed_mutex mux;

void ThreadMainTime()
{
    for (;;) 
    {
        if (mux.try_lock_for(std::chrono::milliseconds(500)))
        {
            std::cout << i << "Try lock for timeout" << std::endl;
            continue;
        }
        mux.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

int main()
{
    for (int i = 0; i < 3; i++) 
    {
        std::thread th(ThreadMainTime);
        th.detach();
    }
    getchar();
    return 0;
}