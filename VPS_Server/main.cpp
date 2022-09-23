#include <glog/logging.h>

#include "env/glog_setting.h"

#include "basic_class/TheSingle.h"

#include "source/network/tcp_obj.h"

int main(int argc, char** argv)
{
    InitLog(argc, argv);

    TheSingle::GetInstance()->InitInsClass();

    GetClass<NetInterface>("NetInterface")->RunUntilQuit();

    DeinitLogger();
    return 0;
}