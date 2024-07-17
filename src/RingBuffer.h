#pragma once

#include <cstddef>
#include <iostream>

namespace project
{
    template <class T>
    class RingBuffer
    {
    public:
        explicit RingBuffer(size_t size) : buffer(size), head(0), tail(0), count(0) {}

        bool isFull() const;

        bool isEmpty() const;

        void write(const T &data);

        T read();

    private:
        project::Vector<T> buffer;
        size_t head;
        size_t tail;
        size_t count;
    };

    template<class T>
    bool RingBuffer<T>::isFull() const
    {
        return count == buffer.size();
    }

    template <class T>
    bool RingBuffer<T>::isEmpty() const
    {
        return count == 0;
    }

    template<class T>
    void RingBuffer<T>::write(const T &data)
    {
        if (isFull())
        {
            std::cerr << "Buffer is full" << std::endl;
            return;
        }
        buffer[head] = data;
        head = (head + 1) % buffer.size();
        count++;
    }

    template <class T>
    T RingBuffer<T>::read()
    {
        if (isEmpty())
        {
            std::cerr << "Buffer is empty" << std::endl;
            return T();
        }
        T data = buffer[tail];
        tail = (tail + 1) % buffer.size();
        count--;
        return data;
    }
}