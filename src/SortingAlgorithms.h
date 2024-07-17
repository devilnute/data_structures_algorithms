#pragma once

#include <cstddef>

namespace project
{
    template <class T>
    void bubbleSort(T *arr, size_t size)
    {
        for (size_t i = 1; i < size; ++i)
        {
            for (size_t j = 0; j < i; ++j)
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
    void selectionSort(T *arr, size_t size)
    {
        for (size_t i = 0; i < size - 1; ++i)
        {
            size_t minIndex = i;
            for (size_t j = i + 1; j < size; ++j)
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
    void insertionSort(T *arr, size_t size)
    {
        size_t i, j;
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
    size_t partition(T *arr, size_t left, size_t right)
    {
        T pivot = arr[right];
        size_t i = left - 1;

        for (size_t j = left; j < right; ++j)
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
    void quickSort(T *arr, size_t left, size_t right)
    {
        if (left < right)
        {
            size_t pivotIndex = partition(arr, left, right);
            if (pivotIndex > 0)
            {
                quickSort(arr, left, pivotIndex - 1);
            }

            quickSort(arr, pivotIndex + 1, right);
        }
    }

    template <class T>
    void quickSort(T *arr, size_t size)
    {
        if (size > 0)
        {
            quickSort(arr, 0, size - 1);
        }
    }

    template <class T>
    void merge(T *arr, size_t left, size_t mid, size_t right)
    {
        size_t n1 = mid - left + 1;
        size_t n2 = right - mid;

        T *leftArray = new T[n1];
        T *rightArray = new T[n2];

        for (size_t i = 0; i < n1; ++i)
            leftArray[i] = arr[left + i];
        for (size_t j = 0; j < n2; ++j)
            rightArray[j] = arr[mid + 1 + j];

        size_t i = 0, j = 0, k = left;
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
    void mergeSort(T *arr, size_t left, size_t right)
    {
        if (left < right)
        {
            size_t mid = left + (right - left) / 2;

            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            merge(arr, left, mid, right);
        }
    }

    template <class T>
    void mergeSort(T *arr, size_t size)
    {
        if (size > 1)
            mergeSort(arr, 0, size - 1);
    }

    template <class T>
    void shellSort(T *arr, size_t size)
    {
        for (size_t gap = size / 2; gap > 0; gap /= 2)
        {
            for (size_t i = gap; i < size; ++i)
            {
                T temp = arr[i];
                size_t j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }

    template <class T>
    void hibbardSort(T *arr, size_t size)
    {
        size_t k = 1;
        while ((1 << k) - 1 < size)
        {
            ++k;
        }
        while (k > 0)
        {
            size_t gap = (1 << k) - 1;
            for (size_t i = gap; i < size; ++i)
            {
                T temp = arr[i];
                size_t j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
            --k;
        }
    }
}
