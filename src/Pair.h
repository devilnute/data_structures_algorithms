#pragma once

#include <cstddef>

namespace project
{
    template <class T1, class T2>
    class Pair
    {
    public:
        T1 first;
        T2 second;

        Pair();
        Pair(const T1 &a, const T2 &b);
        Pair(const Pair &other);
        Pair(Pair &&other) noexcept;

        Pair &operator=(const Pair &other);
        Pair &operator=(Pair &&other) noexcept;

        bool operator==(const Pair &other) const;
        bool operator!=(const Pair &other) const;
    };

    template <class T1, class T2>
    Pair<T1, T2>::Pair() : first(T1()), second(T2()) {}

    template <class T1, class T2>
    Pair<T1, T2>::Pair(const T1 &a, const T2 &b) : first(a), second(b) {}

    template <class T1, class T2>
    Pair<T1, T2>::Pair(const Pair &other) : first(other.first), second(other.second) {}

    template <class T1, class T2>
    Pair<T1, T2>::Pair(Pair &&other) noexcept : first(std::move(other.first)), second(std::move(other.second)) {}

    template <class T1, class T2>
    Pair<T1, T2> &Pair<T1, T2>::operator=(const Pair &other)
    {
        if (this != &other)
        {
            first = other.first;
            second = other.second;
        }
        return *this;
    }

    template <class T1, class T2>
    Pair<T1, T2> &Pair<T1, T2>::operator=(Pair &&other) noexcept
    {
        if (this != &other)
        {
            first = std::move(other.first);
            second = std::move(other.second);
        }
        return *this;
    }

    template <class T1, class T2>
    bool Pair<T1, T2>::operator==(const Pair &other) const
    {
        return first == other.first && second == other.second;
    }

    template <class T1, class T2>
    bool Pair<T1, T2>::operator!=(const Pair &other) const
    {
        return !(*this == other);
    }
}