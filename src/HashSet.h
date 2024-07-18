#pragma once

#include <cstddef>
#include <optional>

#include "DoublyLinkedList.h"
#include "DynamicArray.h"

namespace project
{
    template <class KeyType, class Hash = std::hash<KeyType>>
    class HashSet
    {
    public:
        HashSet(size_t size = 10);

        void insert(const KeyType &key);
        bool find(const KeyType &key);
        void remove(const KeyType &key);

        void print();

    private:
        project::Vector<project::List<KeyType>> table_;
        Hash hash_fn;

        size_t get_index(const KeyType &key) const;
    };

    template <class KeyType, class Hash>
    HashSet<KeyType, Hash>::HashSet(size_t size)
        : table_(size) {}

    template <class KeyType, class Hash>
    size_t HashSet<KeyType, Hash>::get_index(const KeyType &key) const
    {
        return hash_fn(key) % table_.size();
    }

    template <class KeyType, class Hash>
    void HashSet<KeyType, Hash>::insert(const KeyType &key)
    {
        size_t index = get_index(key);
        ListNode<KeyType> *current = table_[index].getHead();
        while (current)
        {
            if (current->data == key)
            {
                throw Exception("Key already exists!");
            }
            current = current->next;
        }
        table_[index].push_back(key);
    }

    template <class KeyType, class Hash>
    bool HashSet<KeyType, Hash>::find(const KeyType &key)
    {
        size_t index = get_index(key);
        ListNode<KeyType> *current = table_[index].getHead();
        while (current)
        {
            if (current->data == key)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    template <class KeyType, class Hash>
    void HashSet<KeyType, Hash>::remove(const KeyType &key)
    {
        size_t index = get_index(key);
        ListNode<KeyType> *current = table_[index].getHead();
        while (current)
        {
            if (current->data == key)
            {
                table_[index].remove(key);
                return;
            }
            current = current->next;
        }
    }

    template <class KeyType, class Hash>
    void HashSet<KeyType,Hash>::print()
    {
        std::cout << "{ ";
        for (size_t i = 0; i < table_.size(); ++i)
        {
            ListNode<KeyType> *current = table_[i].getHead();            
            while (current)
            {
                std::cout << current->data << ' ';
                current = current->next;
            }
        }
        std::cout << "}\n";
    }
}
