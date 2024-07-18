#pragma once

#include <cstddef>
#include <initializer_list>

#include "MyException.h"

namespace project
{
    template <class T>
    class Deque
    {
    public:
        Deque();
        Deque(std::initializer_list<T> init);
        ~Deque();

        void push_front(const T &value);
        void push_back(const T &value);
        void pop_front();
        void pop_back();

        T &operator[](size_t index);
        const T &operator[](size_t index) const;

        T &front();
        T &back();
        const T &front() const;
        const T &back() const;

        bool empty() const;
        size_t size() const;

        void print() const;

    private:
        struct Node
        {
            T *data_;
            size_t capacity_;
            size_t front_;
            size_t back_;
            Node *next_;
            Node *prev_;

            Node(size_t cap)
                : capacity_(cap), front_(cap / 2), back_(cap / 2 - 1), next_(nullptr), prev_(nullptr)
            {
                data_ = new T[capacity_];
            }

            ~Node()
            {
                delete[] data_;
            }

            bool is_full() const
            {
                return back_ - front_ + 1 == capacity_;
            }

            bool is_empty() const
            {
                return front_ > back_;
            }

            void push_front(const T &value)
            {
                if (front_ == 0)
                {
                    throw Exception("Node is full at the front");
                }
                data_[--front_] = value;
            }

            void push_back(const T &value)
            {
                if (back_ == capacity_ - 1)
                {
                    throw Exception("Node is full at the back");
                }
                data_[++back_] = value;
            }

            void pop_front()
            {
                if (is_empty())
                {
                    throw Exception("Node is empty");
                }
                ++front_;
            }

            void pop_back()
            {
                if (is_empty())
                {
                    throw Exception("Node is empty");
                }
                --back_;
            }

            T &front_element()
            {
                if (is_empty())
                {
                    throw Exception("Node is empty");
                }
                return data_[front_];
            }

            T &back_element()
            {
                if (is_empty())
                {
                    throw Exception("Node is empty");
                }
                return data_[back_];
            }
        };

        Node *head_;
        Node *tail_;
        size_t node_capacity_;
        size_t deque_size_;

        void create_initial_node();
    };

    template <class T>
    Deque<T>::Deque() : head_(nullptr), tail_(nullptr), node_capacity_(16), deque_size_(0)
    {
        create_initial_node();
    }

    template <class T>
    Deque<T>::Deque(std::initializer_list<T> init)
    {
        for(const T &e: init)
        {
            push_back(e);
        }
    }

    template <class T>
    Deque<T>::~Deque()
    {
        while (head_)
        {
            Node *temp = head_;
            head_ = head_->next_;
            delete temp;
        }
    }

    template <class T>
    void Deque<T>::push_front(const T &value)
    {
        if (head_->is_full())
        {
            Node *new_node = new Node(node_capacity_);
            new_node->next_ = head_;
            head_->prev_ = new_node;
            head_ = new_node;
        }
        head_->push_front(value);
        ++deque_size_;
    }

    template <class T>
    void Deque<T>::push_back(const T &value)
    {
        if (tail_->is_full())
        {
            Node *new_node = new Node(node_capacity_);
            new_node->prev_ = tail_;
            tail_->next_ = new_node;
            tail_ = new_node;
        }
        tail_->push_back(value);
        ++deque_size_;
    }

    template <class T>
    void Deque<T>::pop_front()
    {
        if (head_->is_empty())
        {
            if (head_ == tail_)
            {
                throw Exception("Deque is empty");
            }
            Node *temp = head_;
            head_ = head_->next_;
            head_->prev_ = nullptr;
            delete temp;
        }
        head_->pop_front();
        --deque_size_;
    }

    template <class T>
    void Deque<T>::pop_back()
    {
        if (tail_->is_empty())
        {
            if (head_ == tail_)
            {
                throw Exception("Deque is empty");
            }
            Node *temp = tail_;
            tail_ = tail_->prev_;
            tail_->next_ = nullptr;
            delete temp;
        }
        tail_->pop_back();
        --deque_size_;
    }

    template <class T>
    T &Deque<T>::front()
    {
        return head_->front_element();
    }

    template <class T>
    T &Deque<T>::back()
    {
        return tail_->back_element();
    }

    template <class T>
    const T &Deque<T>::front() const
    {
        return head_->front_element();
    }

    template <class T>
    const T &Deque<T>::back() const
    {
        return tail_->back_element();
    }

    template <class T>
    bool Deque<T>::empty() const
    {
        return deque_size_ == 0;
    }

    template <class T>
    size_t Deque<T>::size() const
    {
        return deque_size_;
    }

    template <class T>
    void Deque<T>::create_initial_node()
    {
        head_ = new Node(node_capacity_);
        tail_ = head_;
    }

    template <class T>
    T &Deque<T>::operator[](size_t index)
    {
        if (index >= deque_size_)
        {
            throw Exception("Index out of range");
        }

        Node *current = head_;
        size_t current_index = 0;
        while (current)
        {
            size_t node_size = current->back_ - current->front_ + 1;
            if (index < node_size)
            {
                return current->data_[current->front_ + index];
            }
            index -= node_size;
            current = current->next_;
        }

        throw Exception("Index out of range");
    }

    template <class T>
    const T &Deque<T>::operator[](size_t index) const
    {
        if (index >= deque_size_)
        {
            throw Exception("Index out of range");
        }

        Node *current = head_;
        size_t current_index = 0;
        while (current)
        {
            size_t node_size = current->back_ - current->front_ + 1;
            if (index < node_size)
            {
                return current->data_[current->front_ + index];
            }
            index -= node_size;
            current = current->next_;
        }

        throw Exception("Index out of range");
    }

    template <class T>
    void Deque<T>::print() const
    {
        Node *current = head_;
        while (current)
        {
            for (size_t i = current->front_; i <= current->back_; ++i)
            {
                std::cout << current->data_[i] << " ";
            }
            current = current->next_;
        }
        std::cout << std::endl;
    }
}
