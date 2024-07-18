#pragma once

#include <cstddef>
#include <optional>

#include "DoublyLinkedList.h"
#include "DynamicArray.h"
#include "Pair.h"

namespace project
{
    template <class KeyType, class ValueType, class Hash = std::hash<KeyType>>
    class HashMap
    {
    public:
        HashMap(size_t size = 10);

        void insert(const KeyType &key, const ValueType &value);
        bool find(const KeyType &key);
        void remove(const KeyType &key);

        void print();

    private:
        project::Vector<project::List<project::Pair<KeyType, ValueType>>> table_;
        Hash hash_fn;

        size_t get_index(const KeyType &key) const;
    };

    template <class KeyType, class ValueType, class Hash>
    HashMap<KeyType, ValueType, Hash>::HashMap(size_t size) : table_(size) {}

    template <class KeyType, class ValueType, class Hash>
    size_t HashMap<KeyType, ValueType, Hash>::get_index(const KeyType &key) const
    {
        return hash_fn(key) % table_.size();
    }

    template <class KeyType, class ValueType, class Hash>
    void HashMap<KeyType, ValueType, Hash>::insert(const KeyType &key, const ValueType &value)
    {

        size_t index = get_index(key);
        ListNode<Pair<KeyType, ValueType>> *current = table_[index].getHead();
        while (current)
        {
            if (current->data.first == key)
            {
                throw Exception("Key already exists!");
            }
            current = current->next;
        }
        table_[index].push_back(Pair{key, value});
    }

    template <class KeyType, class ValueType, class Hash>
    bool HashMap<KeyType, ValueType, Hash>::find(const KeyType &key)
    {
        size_t index = get_index(key);
        ListNode<Pair<KeyType, ValueType>> *current = table_[index].getHead();
        while (current)
        {
            if (current->data.first == key)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    template <class KeyType, class ValueType, class Hash>
    void HashMap<KeyType, ValueType, Hash>::remove(const KeyType &key)
    {
        size_t index = get_index(key);
        ListNode<Pair<KeyType, ValueType>> *current = table_[index].getHead();
        while (current)
        {
            if (current->data.first == key)
            {
                table_[index].remove(current->data);
                return;
            }
            current = current->next;
        }
    }

    template <class KeyType, class ValueType, class Hash>
    void HashMap<KeyType, ValueType, Hash>::print()
    {
        for (size_t i = 0; i < table_.size(); ++i)
        {

            ListNode<Pair<KeyType, ValueType>> *current = table_[i].getHead();
            while (current)
            {
                std::cout << current->data.first << ": " << current->data.second << '\n';
                current = current->next;
            }
        }
    }
}
