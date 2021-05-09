#include "thread_pool.hpp"
#include <iostream>

using namespace std;

/********************
 *  初始化线程池
 *  @para num 线程池数量
 * 
 *******************/
void ThreadPool::Init(int num)
{
    unique_lock<mutex> lock(mux_);
    this->thread_num_ = num;
    cout << "Thread pool init " << num << endl;
    

}

/**
 *  启动所有线程，必须先调用Init
 *  
 * 
 */
void ThreadPool::Start()
{
    unique_lock<mutex> lock(mux_);

    if (thread_num_ <= 0)
    {
        cerr << "Please init ThreadPool" << endl;
        return;
    }

    if (!threads_.empty())
    {
        cerr << "Thread pool has start!" << endl;
        return;
    }

    for (int i = 0; i < thread_num_; i++)
    {
        // auto th = new thread(&ThreadPool::Run, this);
        // threads_.push_back(th);
        auto th = make_shared<thread>(&ThreadPool::Run, this);
        threads_.push_back(th);
        
    }
}

/**
     * 线程池退出
     *  
     */
void ThreadPool::Stop()
{
    is_exit_ = true;
    cv_.notify_all();

    for (auto& th: threads_)
    {
        th->join();
    }

    unique_lock<mutex> lock(mux_);
    threads_.clear();



}

/**
 *  线程池线程的入口函数
 * 
 */
void ThreadPool::Run()
{
    cout << "Begin threadpool run " << this_thread::get_id() << endl;

    while (!is_exit()) 
    {
        auto task = GetTask();
        if (!task) continue;
        ++task_run_count_;
        try
        {
            auto re = task->Run();
            task->SetValue(re);
        }
        catch (...)
        {

        }
        --task_run_count_;
    }

    cout << "End threadpool run " << this_thread::get_id() << endl;
}

void ThreadPool::AddTask(std::shared_ptr<Task> task)
{
    unique_lock<mutex> lock(mux_);
    tasks_.push_back(task);
    task->is_exit = [this] {return is_exit();};
    lock.unlock();
    cv_.notify_one();


}

std::shared_ptr<Task> ThreadPool::GetTask()
{
    unique_lock<mutex> lock(mux_);

    if (tasks_.empty()) 
    {
        cv_.wait(lock);
    }

    if (is_exit()) 
        return nullptr;

    if (tasks_.empty())
        return nullptr;

    auto task = tasks_.front();
    tasks_.pop_front();
    return task;
}