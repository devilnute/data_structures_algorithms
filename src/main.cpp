#include <iostream>
#include <ctime>

#include "SearchAlgorithms.h"
#include "SortingAlgorithms.h"
#include "Timer.h"

int main()
{
    srand(time(NULL));

    std::size_t size = 9;
    int *arr = new int[size]{121, 23124, 552346, 1223, 53, 1623, 51, 28, 1245};

    project::mergeSort(arr, size);

    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << std::endl;
    }

    delete[] arr;
    return 0;
}
