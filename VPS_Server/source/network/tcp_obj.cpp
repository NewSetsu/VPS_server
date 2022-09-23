#include "tcp_obj.h"
#include "basic_class/TheSingle.h"

DECLARE_OBJ(NetInterface);

using namespace evpp;

NetInterface::NetInterface() : BasicClass("NetInterface") {
    // do nothing
}

void NetInterface::LocalInit() {
    m_base_thread.reset(new evpp::EventLoopThread());
    m_base_thread->Start(true);

    //m_thread_pool.reset(new evpp::EventLoopThreadPool(m_base_thread->loop(), 2));
    //m_thread_pool->Start(true);
}

void NetInterface::FinishInit() {
    m_svr.reset(new evpp::TCPServer(m_base_thread->loop(), "0.0.0.0:9090", "MAIN", 2));
    m_svr->Init();
    m_svr->SetConnectionCallback([this](const TCPConnPtr& con) {
        if (con->IsConnected()) {
            LOG(INFO) << "Connect " << con->AddrToString();
        } else {
            LOG(INFO) << "Disconnect " << con->AddrToString();
        }
        });
    m_svr->SetMessageCallback([this](const TCPConnPtr& con, Buffer* bf) {
        LOG(INFO) << "Message from :" << con->AddrToString() << ": " << bf->NextAllString();
        });

    m_svr->Start();

}

void NetInterface::RunUntilQuit() {
    while (!is_shutdown) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

