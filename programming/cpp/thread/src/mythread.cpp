#include <iostream>
#include <thread>
#include <string>
#include <sstream>
#include "thread_executor.hpp"
#include "thread_pool.hpp"

using namespace std;
using namespace this_thread;
using namespace chrono;

bool is_exit = false;

class Para
{
public:
    Para () { cout << "Create Para" << endl; }
    ~Para() { cout << "Drop Para" << endl; }
    string name;
};

void ThreadMain()
{
    cout << "Starting sub thread " << this_thread::get_id() << endl;
    for (int i = 0; i < 10; i++) 
    {   
        if (!is_exit) break;
        cout << "in thread id = " << i << endl;
        sleep_for(seconds(1));
    }
    cout << "End of sub thread " << this_thread::get_id() << endl;
}

void ThreadMainWithParams(int p1, float p2, string str, Para p4)
{
    this_thread::sleep_for(milliseconds(100));
    cout << "ThreadMain " << p1 << " " << p2 << " " << str << endl; 
}


class MyTask: public Task {
public:
    int Run()
    {
        cout << "MyTask" << name << endl;
        for (int i = 0; i < 10; i++)
        {
            if (is_exit()) break;
            cout << "." << flush;
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }
    std::string name = "";

};


int main(int argc, char** argv) {

    
    // testThreadObj();

    // testThreadMainWithParams();
    // {
    //     thread th(ThreadMain);
    //     th.detach(); // 子线程与主线程分离 守护线程
    //     // 坑: 主线程退出后 子线程不一定退出
    // }

    // {
    //     cout << "Main Thread " << this_thread::get_id() << endl;
    //     thread th(ThreadMain);
    //     // 等待子线程退出
    //     is_exit = true; // 通知子线程退出
    //     th.join();
    //     cout << "子线程已经退出!" << endl;
    // }
    // thread th;
    // {
    //     float f1 = 12.1f;
    //     Para p;
    //     p.name = "test Para class";
    //     th = thread(ThreadMainWithParams, 101, f1, "test string parameters", p);  
    // }
    // th.join();

    // ThreadExecutor thread_executor;
    // thread_executor.name = "TestThreadExecutor";
    // thread_executor.Start();
    
    // this_thread::sleep_for(std::chrono::seconds(2));
    // thread_executor.Stop();
    
    // thread_executor.Wait();

    // MsgServer server;
    // server.Start();
    // for (int i = 0; i < 10; i++)
    // {
    //     std::stringstream ss;
    //     ss << "msg: " << i+1;
    //     server.SendMsg(ss.str());
    //     this_thread::sleep_for(chrono::milliseconds(500));
    // }
    // server.Stop();

    ThreadPool pool;
    pool.Init(4);
    pool.Start();

    // MyTask task1;
    // task1.name = "test name 001";
    // pool.AddTask(&task1);
    auto task3 = make_shared<MyTask> ();
    task3->name = "test shared 003";
    pool.AddTask(task3);
    

    // MyTask task2;
    // task2.name = "test name 002";
    // pool.AddTask(&task2);
    auto task4 = make_shared<MyTask>();
    task4->name = "test shared 004";
    pool.AddTask(task4);
    auto re = task4->GetReturn(); 
    cout << "task4 " << re << endl;

    this_thread::sleep_for(chrono::milliseconds(100));

    this_thread::sleep_for(chrono::milliseconds(1000));
    pool.Stop();
    cout << "Task run count = " << pool.task_run_count() << endl;


    return 0;
}