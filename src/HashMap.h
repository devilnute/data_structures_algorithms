#pragma once

#include <iostream>

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
        bool find(const KeyType &key, ValueType &value) const;
        void remove(const KeyType &key);

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
        for (auto &pair : table_[index])
        {
            if (pair.first == key)
            {
                std::cerr << "Key already exists!" << std::endl;
                return;
            }
        }
        table_[index].emplace_back(key, value);
    }

    template <class KeyType, class ValueType, class Hash>
    bool HashMap<KeyType, ValueType, Hash>::find(const KeyType &key, ValueType &value) const
    {
        size_t index = get_index(key);
        for (const auto &pair : table_[index])
        {
            if (pair.first == key)
            {
                value = pair.second;
                return true;
            }
        }
        return false;
    }

    template <class KeyType, class ValueType, class Hash>
    void HashMap<KeyType, ValueType, Hash>::remove(const KeyType &key)
    {
        size_t index = get_index(key);
        for (auto it = table_[index].begin(); it != table_[index].end(); ++it)
        {
            if (it->first == key)
            {
                table_[index].erase(it);
                return;
            }
        }
    }
}