#pragma once

#include "DoublyLinkedList.h"
#include "MyDeque.h"

namespace project
{
    template <class T, class Container = project::Deque<T>>
    class Queue
    {
    public:
        Queue() = default;

        void push(const T &value);
        void pop();
        T &front();
        const T &front() const;
        T &back();
        const T &back() const;
        bool empty() const;
        size_t size() const;

    private:
        Container container_;
    };

    template <class T, class Container>
    void Queue<T, Container>::push(const T &value)
    {
        container_.push_back(value);
    }

    template <class T, class Container>
    void Queue<T, Container>::pop()
    {
        if (container_.empty())
        {
            throw Exception("Queue is empty");
        }
        container_.pop_front();
    }

    template <class T, class Container>
    T &Queue<T, Container>::front()
    {
        if (container_.empty())
        {
            throw Exception("Queue is empty");
        }
        return container_.front();
    }

    template <class T, class Container>
    const T &Queue<T, Container>::front() const
    {
        if (container_.empty())
        {
            throw Exception("Queue is empty");
        }
        return container_.front();
    }

    template <class T, class Container>
    T &Queue<T, Container>::back()
    {
        if (container_.empty())
        {
            throw Exception("Queue is empty");
        }
        return container_.back();
    }

    template <class T, class Container>
    const T &Queue<T, Container>::back() const
    {
        if (container_.empty())
        {
            throw Exception("Queue is empty");
        }
        return container_.back();
    }

    template <class T, class Container>
    bool Queue<T, Container>::empty() const
    {
        return container_.empty();
    }

    template <class T, class Container>
    size_t Queue<T, Container>::size() const
    {
        return container_.size();
    }
}
