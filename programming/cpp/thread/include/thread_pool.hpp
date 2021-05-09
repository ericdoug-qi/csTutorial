#ifndef __H_THREAD_POOL_H__

#include <thread>
#include <mutex>
#include <vector>
#include <list>
#include <atomic>
#include <functional>

class Task
{
public:
    virtual int Run() = 0;
    std::function<bool()> is_exit = nullptr;
};

class ThreadPool
{
public:
    /********************
     *  初始化线程池
     *  @para num 线程池数量
     * 
     *******************/


    void Init(int num);
    /**
     *  启动所有线程，必须先调用Init
     *  
     * 
     */
    void Start();


    void AddTask(Task *task);

    Task* GetTask();

    /**
     * 线程池退出
     *  
     */
    void Stop();

    bool is_exit() { return is_exit_; }


    int task_run_count() { return task_run_count_; }


private:
    /**
     *  线程池线程的入口函数
     * 
     */
    void Run() {};
    int thread_num_ = 0;  // 线程数量
    std::mutex mux_;
    std::vector<std::thread*> threads_;
    std::list<Task*> tasks_;
    std::condition_variable cv_;
    bool is_exit_ = false; // 线程池退出
    std::atomic<int> task_run_count_ = {0}; // 正在运行的task数量 


};

#endif 