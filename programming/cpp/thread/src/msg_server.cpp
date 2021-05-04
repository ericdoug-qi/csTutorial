#include "msg_server.hpp"

void MsgServer::SendMsg(std::string msg)
{
    std::unique_lock<std::mutex> lock(mux_);
    msgs_.push_back(msg);

}


// 处理消息的线程入口函数
void MsgServer::Main()
{
    while(!is_exit())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::unique_lock<std::mutex> lock(mux_);
        if (msgs_.empty()) 
            continue;

        while(!msgs_.empty())
        {
            std::cout<< "recv: " << msgs_.front() << std::endl;
            msgs_.pop_front();
        }
    }
}
