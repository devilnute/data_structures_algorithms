#pragma once

namespace project
{
    template <class T>
    bool isOrdered(T *arr, std::size_t size)
    {
        for (std::size_t i = 0; i < size - 1; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                return 0;
            }
        }
        return 1;
    }

    template <class T>
    T *linearSearch(T *arr, std::size_t size, const T &val)
    {
        for (std::size_t i = 0; i < size; ++i)
        {
            if (arr[i] == val)
            {
                return &arr[i];
            }
        }
        return nullptr;
    }

    template <class T>
    T *iterativeBinarySearch(T *arr, std::size_t size, const T &val)
    {
        if (!isOrdered(arr, size))
        {
            return nullptr;
        }

        std::size_t low = 0;
        std::size_t high = size - 1;

        while (low <= high)
        {
            std::size_t mid = low + ((high - low) / 2);

            if (arr[mid] == val)
            {
                return &arr[mid];
            }
            if (arr[mid] < val)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return nullptr;
    }

    template <class T>
    T *binarySearchRecursion(T *arr, std::size_t low, std::size_t high, const T &val)
    {
        if (high < low)
        {
            return nullptr;
        }

        std::size_t mid = low + ((high - low) / 2);

        if (arr[mid] == val)
        {
            return &arr[mid];
        }
        else if (arr[mid] < val)
        {
            return binarySearchRecursion(arr, mid + 1, high, val);
        }
        else
        {
            return binarySearchRecursion(arr, low, mid - 1, val);
        }
    }

    template <class T>
    T *recursiveBinarySearch(T *arr, std::size_t size, const T &val)
    {
        if (!isOrdered(arr, size))
        {
            return nullptr;
        }

        return binarySearchRecursion(arr, 0, size - 1, val);
    }

    template <class T>
    std::pair<T *, T *> twoPointerSearch(T *arr, std::size_t size, const T &sum)
    {
        if (!isOrdered(arr, size))
        {
            return std::pair<T *, T *>(nullptr, nullptr);
        }

        std::size_t i = 0;
        std::size_t j = size - 1;

        while (i < j)
        {
            if (arr[i] + arr[j] == sum)
            {
                return std::pair<T *, T *>(&arr[i], &arr[j]);
            }

            if ((arr[i] + arr[j]) < sum)
            {
                ++i;
            }
            else
            {
                ++j;
            }
        }
        return std::pair<T *, T *>(nullptr, nullptr);
    }

    template <class T>
    std::pair<T*, T*> maximumSubarray(T *arr, std::size_t size)
    {
        // Kadane's algorithm
        T sum = 0;
        T maxSum = INT32_MIN;
        std::size_t maxStart = 0;
        std::size_t maxEnd = 0;

        for (std::size_t i = 0; i < size - 1; ++i)
        {
            sum += arr[i];

            if (arr[i] > sum)
            {
                sum = arr[i];
                maxStart = i;
            }

            if (sum > maxSum)
            {
                maxSum = sum;
                maxEnd = i;
            }
        }
        return std::pair<T*,T*>(&arr[maxStart], &arr[maxEnd]);
    }
}
