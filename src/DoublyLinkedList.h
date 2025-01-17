#pragma once

#include <cstddef>
#include <iostream>
#include <initializer_list>

#include "MyException.h"

namespace project
{
    template <class T>
    struct ListNode
    {
        T data;
        ListNode *next;
        ListNode *prev;

        ListNode(const T &value) : data(value), next(nullptr), prev(nullptr) {}
    };

    template <class T>
    class List
    {
    public:
        List();
        List(std::initializer_list<T> init);
        ~List();

        void push_front(const T &value);
        void push_back(const T &value);
        void remove(const T &value);
        void pop_front();
        void pop_back();

        T &front();
        T &back();
        const T &front() const;
        const T &back() const;

        bool empty() const;
        size_t size() const;
        ListNode<T> *getHead();

        void print() const;

    private:
        ListNode<T> *head_;
        ListNode<T> *tail_;
        size_t size_;
    };

    template <class T>
    List<T>::List() : head_(nullptr), tail_(nullptr), size_(0) {}

    template <class T>
    List<T>::List(std::initializer_list<T> init)
    {
        for (const T &e : init)
        {
            push_back(e);
        }
    }

    template <class T>
    List<T>::~List()
    {
        while (head_)
        {
            ListNode<T> *temp = head_;
            head_ = head_->next;
            delete temp;
        }
    }

    template <class T>
    void List<T>::push_front(const T &value)
    {
        ListNode<T> *new_node = new ListNode<T>(value);
        new_node->next = head_;
        if (head_)
        {
            head_->prev = new_node;
        }
        else
        {
            tail_ = new_node;
        }
        head_ = new_node;
        ++size_;
    }

    template <class T>
    void List<T>::push_back(const T &value)
    {
        ListNode<T> *new_node = new ListNode<T>(value);
        new_node->prev = tail_;
        if (tail_)
        {
            tail_->next = new_node;
        }
        else
        {
            head_ = new_node;
        }
        tail_ = new_node;
        ++size_;
    }

    template <class T>
    void List<T>::pop_front()
    {
        if (!head_)
        {
            throw Exception("List is empty");
        }
        ListNode<T> *temp = head_;
        head_ = head_->next;
        if (head_)
        {
            head_->prev = nullptr;
        }
        else
        {
            tail_ = nullptr;
        }
        delete temp;
        --size_;
    }

    template <class T>
    void List<T>::pop_back()
    {
        if (!tail_)
        {
            throw Exception("List is empty");
        }
        ListNode<T> *temp = tail_;
        tail_ = tail_->prev;
        if (tail_)
        {
            tail_->next = nullptr;
        }
        else
        {
            head_ = nullptr;
        }
        delete temp;
        --size_;
    }

    template <class T>
    T &List<T>::front()
    {
        if (!head_)
        {
            throw Exception("List is empty");
        }
        return head_->data;
    }

    template <class T>
    T &List<T>::back()
    {
        if (!tail_)
        {
            throw Exception("List is empty");
        }
        return tail_->data;
    }

    template <class T>
    const T &List<T>::front() const
    {
        if (!head_)
        {
            throw Exception("List is empty");
        }
        return head_->data;
    }

    template <class T>
    const T &List<T>::back() const
    {
        if (!tail_)
        {
            throw Exception("List is empty");
        }
        return tail_->data;
    }

    template <class T>
    bool List<T>::empty() const
    {
        return head_ == nullptr;
    }

    template <class T>
    size_t List<T>::size() const
    {
        return size_;
    }

    template <class T>
    void List<T>::print() const
    {
        ListNode<T> *current = head_;
        while (current)
        {
            std::cout << current->data << ' ';
            current = current->next;
        }
        std::cout << std::endl;
    }

    template <class T>
    void List<T>::remove(const T &value)
    {
        ListNode<T> *current = head_;

        while (current)
        {
            if (current->data == value)
            {
                ListNode<T> *to_delete = current;
                if (current->prev)
                {
                    current->prev->next = current->next;
                }
                else
                {
                    head_ = current->next;
                }

                if (current->next)
                {
                    current->next->prev = current->prev;
                }
                else
                {
                    tail_ = current->prev;
                }

                current = current->next;
                delete to_delete;
                --size_;
            }
            else
            {
                current = current->next;
            }
        }
    }

    template<class T>
    ListNode<T> *List<T>::getHead()
    {
        return head_;
    }
}
