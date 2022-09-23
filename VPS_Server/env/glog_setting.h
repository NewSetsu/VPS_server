#pragma once

#include <boost/filesystem.hpp>
#include <glog/logging.h>
#include <gflags/gflags.h>


void InitLog(int argc, char** argv) {
    google::InitGoogleLogging(*argv);

    boost::filesystem::path log_path("./log");
    if (!boost::filesystem::is_directory(log_path)) {
        boost::filesystem::create_directories(log_path);    }


    FLAGS_log_dir = "./log/";
    FLAGS_alsologtostderr = 1;
}


void DeinitLogger() {
    google::ShutdownGoogleLogging();
}