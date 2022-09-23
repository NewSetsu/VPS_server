#pragma once

#include <evpp/event_loop_thread_pool.h>
#include <evpp/tcp_client.h>
#include <evpp/tcp_server.h>
#include <evpp/tcp_conn.h>
#include <evpp/tcp_callbacks.h>

#include "basic_class/BasicClass.h"

class NetInterface : public BasicClass {
public:
    virtual ~NetInterface() {}
    explicit NetInterface();

    virtual void LocalInit() override;
    virtual void FinishInit() override;

    void RunUntilQuit();

protected:

protected:
    sptr<evpp::TCPServer> m_svr;

    std::mutex m_mtx;
    sptr<evpp::EventLoopThread> m_base_thread;
    //sptr<evpp::EventLoopThreadPool> m_thread_pool;

    std::atomic_bool is_shutdown = false;
};
