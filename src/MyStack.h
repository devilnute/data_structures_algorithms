#pragma once

#include "DoublyLinkedList.h"
#include "DynamicArray.h"
#include "MyDeque.h"

namespace project
{
    template <class T, class Container = project::Deque<T>>
    class Stack
    {
    public:
        Stack() = default;

        void push(const T &value);
        void pop();
        T &top();
        const T &top() const;
        bool empty() const;
        size_t size() const;

    private:
        Container container_;
    };

    template <class T, class Container>
    void Stack<T, Container>::push(const T &value)
    {
        container_.push_back(value);
    }

    template <class T, class Container>
    void Stack<T, Container>::pop()
    {
        if (container_.empty())
        {
            throw Exception("Stack is empty");
        }
        container_.pop_back();
    }

    template <class T, class Container>
    T &Stack<T, Container>::top()
    {
        if (container_.empty())
        {
            throw Exception("Stack is empty");
        }
        return container_.back();
    }

    template <class T, class Container>
    const T &Stack<T, Container>::top() const
    {
        if (container_.empty())
        {
            throw Exception("Stack is empty");
        }
        return container_.back();
    }

    template <class T, class Container>
    bool Stack<T, Container>::empty() const
    {
        return container_.empty();
    }

    template <class T, class Container>
    size_t Stack<T, Container>::size() const
    {
        return container_.size();
    }
}
