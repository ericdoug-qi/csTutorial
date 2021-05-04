#include <iostream>
#include <mutex>
#include <thread>

static std::mutex mux1;
static std::mutex mux2;

void TestScope1()
{   
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    mux1.lock();
    mux2.lock();
    std::cout << "TestScope1" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    mux1.unlock();
    mux2.unlock();

}

void TestScope2()
{
    mux2.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    mux1.lock();
    std::cout << "TestScope2" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    mux1.unlock();
    mux2.unlock();

}

int main(int argc, char* argv[])
{
    {
        // 演示死锁情况
        {
            std::thread th(TestScope1);
            th.detach();
        }

        {
            std::thread th(TestScope2);
            th.detach();
        }
    }

    getchar();

    return 0;
}
