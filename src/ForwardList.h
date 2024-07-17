#pragma once

#include <cstddef>
#include <initializer_list>

#include "MyException.h"

namespace project
{
    template <class T>
    struct ForwardListNode
    {
        T data;
        ForwardListNode *next;

        ForwardListNode(T value) : data(value), next(nullptr) {}
    };

    template <class T>
    class ForwardList
    {
    public:
        ForwardList();
        ForwardList(std::initializer_list<T> init);
        ~ForwardList();

        void push_front(const T &value);
        void pop_front();
        T &front();
        const T &front() const;

        bool empty() const;
        size_t size() const;

    private:
        ForwardListNode<T> *head_;
        size_t size_;
    };

    template <class T>
    ForwardList<T>::ForwardList() : head_(nullptr), size_(0) {}

    template <class T>
    ForwardList<T>::ForwardList(std::initializer_list<T> init)
        : head_(nullptr), size_(0)
    {
        for(const T &e : init)
        {
            push_front(e);
        }
    }

    template <class T>
    ForwardList<T>::~ForwardList()
    {
        while (head_)
        {
            ForwardListNode<T> *temp = head_;
            head_ = head_->next;
            delete temp;
        }
    }

    template <class T>
    void ForwardList<T>::push_front(const T &value)
    {
        ForwardListNode<T> *new_node = new ForwardListNode<T>(value);
        new_node->next = head_;
        head_ = new_node;
        ++size_;
    }

    template <class T>
    void ForwardList<T>::pop_front()
    {
        if (!head_)
        {
            throw Exception("List is empty");
        }
        ForwardListNode<T> *temp = head_;
        head_ = head_->next;
        delete temp;
        --size_;
    }

    template <class T>
    T &ForwardList<T>::front()
    {
        if (!head_)
        {
            throw Exception("List is empty");
        }
        return head_->data;
    }

    template <class T>
    const T &ForwardList<T>::front() const
    {
        if (!head_)
        {
            throw Exception("List is empty");
        }
        return head_->data;
    }

    template <class T>
    bool ForwardList<T>::empty() const
    {
        return head_ == nullptr;
    }

    template <class T>
    size_t ForwardList<T>::size() const
    {
        return size_;
    }
}
