#pragma once

#include <cstddef>
#include <initializer_list>

#include "MyException.h"

namespace project
{
    template <class T, size_t N>
    class Array
    {
    public:
        Array();
        Array(std::initializer_list<T> init);

        T &operator[](std::size_t index);
        const T &operator[](size_t index) const;

        size_t size() const;

        void print() const;

    private:
        T data_[N];
    };

    template <class T, size_t N>
    Array<T, N>::Array()
    {
        for (size_t i = 0; i < N; ++i)
        {
            data_[i] = T();
        }
    }

    template <class T, size_t N>
    Array<T, N>::Array(std::initializer_list<T> init)
    {
        if (init.size() > N)
        {
            throw Exception("Initializer list too long");
        }

        size_t i = 0;
        for (const T &e : init)
        {
            data_[i++] = e;
        }

        for (; i < N; ++i)
        {
            data_[i] = T();
        }
    }

    template <class T, size_t N>
    T &Array<T, N>::operator[](size_t index)
    {
        if (index >= N)
        {
            throw Exception("Index out of bounds");
        }
        return data_[index];
    }

    template <class T, size_t N>
    const T &Array<T, N>::operator[](size_t index) const
    {
        if (index >= N)
        {
            throw Exception("Index out of bounds");
        }
        return data_[index];
    }

    template <class T, size_t N>
    size_t Array<T, N>::size() const
    {
        return N;
    }
}
