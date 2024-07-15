#pragma once

#include <chrono>
#include <iostream>

namespace project
{
    class Timer
    {
    public:
        Timer();
        ~Timer();

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start_, end_;
        
    };
}
