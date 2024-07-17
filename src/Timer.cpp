#include "Timer.h"

namespace project
{
    Timer::Timer()
    {
        start_ = std::chrono::high_resolution_clock::now();
    }

    Timer::~Timer()
    {
        end_ = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = end_ - start_;        
        std::cout << "DURATION: " << duration.count() << " seconds\n";
    }
}
