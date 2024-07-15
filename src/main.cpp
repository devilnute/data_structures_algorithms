#include <iostream>
#include <ctime>

#include "SearchAlgorithms.h"
#include "Timer.h"

int main()
{
    srand(time(NULL));

    std::size_t size = 9;
    int *arr = new int[size]{12, 24, 56, 123, 153, 163, 251, 288, 1245};

    delete[] arr;
    return 0;
}
