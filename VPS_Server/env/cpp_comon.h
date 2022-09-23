#pragma once
#include <atomic>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <set>
#include <thread>
#include <vector>

#include <glog/logging.h>

using ClassName = std::string;

template<typename T> using sptr = std::shared_ptr<T>;

template<typename T1, typename T2> using dict = std::map<T1, T2>;

using Functor = std::function<void()>;
