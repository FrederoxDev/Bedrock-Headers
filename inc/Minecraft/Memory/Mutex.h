#pragma once

#include <mutex>
#include <shared_mutex>

namespace Bedrock {
    namespace Threading {
        typedef std::mutex Mutex;
        typedef std::shared_timed_mutex SharedMutex;
        typedef std::recursive_mutex RecursiveMutex;

        template<class T>
        using UniqueLock = std::unique_lock<T>;
    };
};