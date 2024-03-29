#include <thread>
#include <iostream>
#include <string>
#include <mutex>


static std::mutex mux;

void TestThread() {
    // 获取锁资源， 若没有则阻塞等待
    // mux.lock();
    for(;;) {

        if (!mux.try_lock()) {
            std::cout << "." << std::flush;
            std::this_thread::sleep_for(std::chrono::microseconds(100));
            continue;
        }

        std::cout << "==========================================" << std::endl;
        std::cout << "test 001" << std::endl;
        std::cout << "test 002" << std::endl;
        std::cout << "test 003" << std::endl;
        std::cout << "==========================================" << std::endl;
        mux.unlock();
    }


}


void ThreadMainMux(int i) 
{
    for (;;)
    {
        mux.lock();
        std::cout << i << "[in]" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        mux.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

}

int main(int argc, char* argv[]) {

    for (int i = 0; i < 10; i++) {
        // std::thread th(ThreadMainMux, i+1);
        std::thread th(TestThread);
        th.detach();
    }

    getchar();
    
    return 0;
}