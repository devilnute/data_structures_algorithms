#pragma once

#include "Timer.h"
#include "SearchAlgorithms.h"

namespace project
{
    template <class T>
    void bubbleSort(T *arr, std::size_t size)
    {
        for (std::size_t i = 1; i < size; ++i)
        {
            for (std::size_t j = 0; j < i; ++j)
            {
                if (arr[i] < arr[j])
                {
                    T tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
    }

    template <class T>
    void selectionSort(T *arr, std::size_t size)
    {
        for (std::size_t i = 0; i < size - 1; ++i)
        {
            std::size_t minIndex = i;
            for (std::size_t j = i + 1; j < size; ++j)
            {
                if (arr[j] < arr[minIndex])
                {
                    minIndex = j;
                }
            }
            if (minIndex != i)
            {
                T tmp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = tmp;
            }
        }
    }

    template <class T>
    void insertionSort(T *arr, std::size_t size)
    {
        std::size_t i, j;
        T k;
        for (i = 1; i < size; ++i)
        {
            k = arr[i];
            j = i - 1;

            while (j >= 0 && arr[j] > k)
            {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = k;
        }
    }

    template <class T>
    std::size_t partition(T *arr, std::size_t left, std::size_t right)
    {
        T pivot = arr[right];
        std::size_t i = left - 1;

        for (std::size_t j = left; j < right; ++j)
        {
            if (arr[j] <= pivot)
            {
                ++i;
                T tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
        T tmp = arr[i + 1];
        arr[i + 1] = arr[right];
        arr[right] = tmp;

        return i + 1;
    }

    template <class T>
    void quickSort(T *arr, std::size_t left, std::size_t right)
    {
        if (left < right)
        {
            std::size_t pivotIndex = partition(arr, left, right);
            if (pivotIndex > 0)
            {
                quickSort(arr, left, pivotIndex - 1);
            }
                
            quickSort(arr, pivotIndex + 1, right);
        }
    }

    template <class T>
    void quickSort(T *arr, std::size_t size)
    {
        if (size > 0)
        {
            quickSort(arr, 0, size - 1);
        }
    }

    template <class T>
    void merge(T *arr, std::size_t left, std::size_t mid, std::size_t right)
    {
        std::size_t n1 = mid - left + 1;
        std::size_t n2 = right - mid;

        T *leftArray = new T[n1];
        T *rightArray = new T[n2];

        for (std::size_t i = 0; i < n1; ++i)
            leftArray[i] = arr[left + i];
        for (std::size_t j = 0; j < n2; ++j)
            rightArray[j] = arr[mid + 1 + j];

        std::size_t i = 0, j = 0, k = left;
        while (i < n1 && j < n2)
        {
            if (leftArray[i] <= rightArray[j])
            {
                arr[k] = leftArray[i];
                ++i;
            }
            else
            {
                arr[k] = rightArray[j];
                ++j;
            }
            ++k;
        }

        while (i < n1)
        {
            arr[k] = leftArray[i];
            ++i;
            ++k;
        }

        while (j < n2)
        {
            arr[k] = rightArray[j];
            ++j;
            ++k;
        }

        delete[] leftArray;
        delete[] rightArray;
    }

    template <class T>
    void mergeSort(T *arr, std::size_t left, std::size_t right)
    {
        if (left < right)
        {
            std::size_t mid = left + (right - left) / 2;

            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            merge(arr, left, mid, right);
        }
    }

    template <class T>
    void mergeSort(T *arr, std::size_t size)
    {
        if (size > 1)
            mergeSort(arr, 0, size - 1);
    }

    template <class T>
    void shellSort(T *arr, std::size_t size)
    {
        for (std::size_t gap = size / 2; gap > 0; gap /= 2)
        {
            for (std::size_t i = gap; i < size; ++i)
            {
                T temp = arr[i];
                std::size_t j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }

    template <class T>
    void hibbardSort(T *arr, std::size_t size)
    {
        std::size_t k = 1;
        while ((1 << k) - 1 < size)
        {
            ++k;
        }
        while (k > 0)
        {
            std::size_t gap = (1 << k) - 1;
            for (std::size_t i = gap; i < size; ++i)
            {
                T temp = arr[i];
                std::size_t j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
            --k;
        }
    }

    template <class T>
    void sedgewickSort(T *arr, std::size_t size)
    {
        std::size_t k = 0;
        std::size_t gaps[30];
        std::size_t numGaps = 0;
        while (true)
        {
            std::size_t gap;
            if (k % 2 == 0)
            {
                gap = 9 * (1 << (2 * k)) - 9 * (1 << k) + 1;
            }
            else
            {
                gap = 8 * (1 << (2 * k)) - 6 * (1 << ((k + 1) / 2)) + 1;
            }
            if (gap >= size)
                break;
            gaps[numGaps++] = gap;
            k++;
        }
        std::reverse(gaps, gaps + numGaps);
        for (std::size_t g = 0; g < numGaps; ++g)
        {
            std::size_t gap = gaps[g];
            for (std::size_t i = gap; i < size; ++i)
            {
                T temp = arr[i];
                std::size_t j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }
}
