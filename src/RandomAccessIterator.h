#pragma once

#include <iterator>

namespace project
{

    template <class T>
    class Iterator
    {
    public:
        typedef std::random_access_iterator_tag iterator_category;
        typedef T value_type;
        typedef std::ptrdiff_t difference_type;
        typedef T *pointer;
        typedef T &reference;

        Iterator() : ptr_(nullptr) {}
        Iterator(T *ptr) : ptr_(ptr) {}

        Iterator &operator++();
        Iterator operator++(int);
        Iterator &operator--();
        Iterator operator--(int);
        bool operator==(const Iterator &other);
        bool operator!=(const Iterator &other);
        Iterator operator+(std::size_t dist);
        Iterator operator-(std::size_t dist);
        reference operator*() const { return *ptr_; }

    private:
        T *ptr_;
    };

    template <class T>
    Iterator<T> &Iterator<T>::operator++()
    {
        ++ptr_;
        return *this;
    }

    template <class T>
    Iterator<T> Iterator<T>::operator++(int)
    {
        Iterator<T> temp(*this);
        ++(*this);
        return temp;
    }

    template <class T>
    Iterator<T> &Iterator<T>::operator--()
    {
        --ptr_;
        return *this;
    }

    template <class T>
    Iterator<T> Iterator<T>::operator--(int)
    {
        Iterator<T> tmp(*this);
        ++(this->ptr_);
        return tmp;
    }

    template <class T>
    bool Iterator<T>::operator==(const Iterator<T> &other)
    {
        return ptr_ == other.ptr_;
    }

    template <class T>
    bool Iterator<T>::operator!=(const Iterator<T> &other)
    {
        return ptr_ != other.ptr_;
    }

    template <class T>
    Iterator<T> Iterator<T>::operator+(std::size_t dist)
    {
        return Iterator<T>((this->ptr_)+dist);
    }

    template <class T>
    Iterator<T> Iterator<T>::operator-(std::size_t dist)
    {
        return Iterator<T>((this->ptr_) + dist);
    }

    template <class T>
    static Iterator<T> returnEndIterator(T *arr, std::size_t size)
    {
        return Iterator<T>(arr + size);
    }

    template <class T>
    static Iterator<T> returnBeginIterator(T *arr)
    {
        return Iterator<T>(arr);
    }

    template <class T>
    static std::size_t returnIteratorDistance(Iterator<T> begin, Iterator<T> end)
    {
        std::size_t dist = 0;

        while (begin != end)
        {
            ++dist;
            ++begin;
        }
        
        return dist;
    }
}
