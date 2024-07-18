#pragma once

#include "DynamicArray.h"
#include "MyDeque.h"

namespace project
{
    template <class T, class Container = project::Vector<T>>
    class PriorityQueue
    {
    public:
        PriorityQueue() = default;

        void push(const T &value);
        void pop();
        const T &top() const;
        bool empty() const;

        size_t size() const;
        void print() const;

    private:
        Container container_;

        void sortc(Container &cont);
    };

    template <class T, class Container>
    void PriorityQueue<T, Container>::sortc(Container &cont)
    {
        for (size_t i = 1; i < cont.size(); ++i)
        {
            for (size_t j = 0; j < i;++j)
            {
                if (cont[j] < cont[i])
                {
                    T tmp = cont[i];
                    cont[i] = cont[j];
                    cont[j] = tmp;
                }
            }
        }
    }

    template <class T, class Container>
    void PriorityQueue<T, Container>::push(const T &value)
    {
        container_.push_back(value);
        sortc(container_);
    }

    template <class T, class Container>
    void PriorityQueue<T, Container>::pop()
    {
        if (empty())
        {
            throw Exception("Priority queue is empty");
        }
        container_[0] = container_.back();
        container_.pop_back();
        if (!empty())
        {
            sortc(container_);
        }
    }

    template <class T, class Container>
    const T &PriorityQueue<T, Container>::top() const
    {
        if (empty())
        {
            throw Exception("Priority queue is empty");
        }
        return container_[0];
    }

    template <class T, class Container>
    bool PriorityQueue<T, Container>::empty() const
    {
        return container_.empty();
    }

    template <class T, class Container>
    size_t PriorityQueue<T, Container>::size() const
    {
        return container_.size();
    }

    template <class T, class Container>
    void PriorityQueue<T, Container>::print() const
    {
        container_.print();
    }
}
