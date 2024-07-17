#pragma once

#include <cstddef>
#include <initializer_list>

#include "MyException.h"

namespace project
{
    template <class T>
    class Vector
    {
    public:
        Vector();
        explicit Vector(size_t size);
        Vector(std::initializer_list<T> init);
        Vector(const Vector &other);
        Vector(Vector &&other) noexcept;
        ~Vector();

        Vector &operator=(const Vector &other);
        Vector &operator=(Vector &&other) noexcept;

        T &operator[](size_t index);
        const T &operator[](size_t index) const;

        size_t size() const;
        bool empty() const;
        size_t capacity() const;
        void resize(size_t newSize);

        void push_back(const T &value);
        void pop_back();

    private:
        T *data_;
        size_t size_;
        size_t capacity_;

        void reallocate(size_t newCapacity);
    };

    template <class T>
    Vector<T>::Vector() : data_(nullptr), size_(0), capacity_(0) {}

    template <class T>
    Vector<T>::Vector(std::initializer_list<T> init)
        : data_(new T[init.size()]), size_(init.size()), capacity_(init.size())
    {
        size_t i = 0;
        for (const T &e : init)
        {
            data_[i++] = e;
        }
    }

    template <class T>
    Vector<T>::Vector(size_t size) : data_(new T[size]), size_(size), capacity_(size) {}

    template <class T>
    Vector<T>::Vector(const Vector &other)
        : data_(new T[other.capacity_]), size_(other.size_), capacity_(other.capacity_)
    {

        for (size_t i = 0; i < other.size_; ++i)
        {
            data_[i] = other.data_[i];
        }
    }

    template <class T>
    Vector<T>::Vector(Vector &&other) noexcept
        : data_(other.data_), size_(other.size_), capacity_(other.capacity_)
    {
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    template <class T>
    Vector<T>::~Vector()
    {
        delete[] data_;
    }

    template <class T>
    Vector<T> &Vector<T>::operator=(const Vector &other)
    {
        if (this != &other)
        {
            delete[] data_;
            data_ = new T[other.capacity_];
            size_ = other.size_;
            capacity_ = other.capacity_;
            for (size_t i = 0; i < other.size_; ++i)
            {
                data_[i] = other.data_[i];
            }
        }
        return *this;
    }

    template <class T>
    Vector<T> &Vector<T>::operator=(Vector &&other) noexcept
    {
        if (this != &other)
        {
            delete[] data_;
            data_ = other.data_;
            size_ = other.size_;
            capacity_ = other.capacity_;

            other.data_ = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }
        return *this;
    }

    template <class T>
    T &Vector<T>::operator[](size_t index)
    {
        if (index >= size_)
        {
            throw Exception("Index out of bounds");
        }
        return data_[index];
    }

    template <class T>
    const T &Vector<T>::operator[](std::size_t index) const
    {
        if (index >= size_)
        {
            throw Exception("Index out of bounds");
        }
        return data_[index];
    }

    template <class T>
    std::size_t Vector<T>::size() const
    {
        return size_;
    }

    template <class T>
    std::size_t Vector<T>::capacity() const
    {
        return capacity_;
    }

    template <class T>
    void Vector<T>::resize(std::size_t newSize)
    {
        if (newSize > capacity_)
        {
            reallocate(newSize);
        }
        size_ = newSize;
    }

    template <class T>
    void Vector<T>::push_back(const T &value)
    {
        if (size_ == capacity_)
        {
            reallocate(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        data_[size_++] = value;
    }

    template <class T>
    void Vector<T>::pop_back()
    {
        if (size_ == 0)
        {
            throw Exception("Vector is empty");
        }
        --size_;
    }

    template <class T>
    void Vector<T>::reallocate(std::size_t newCapacity)
    {
        T *newData = new T[newCapacity];
        for (std::size_t i = 0; i < size_; ++i)
        {
            newData[i] = data_[i];
        }
        delete[] data_;
        data_ = newData;
        capacity_ = newCapacity;
    }

    template <class T>
    bool Vector<T>::empty() const
    {
        return size_ == 0;
    }
}
