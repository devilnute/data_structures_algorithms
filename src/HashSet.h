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
        bool find(const KeyType &key) const;
        void remove(const KeyType &key);

    private:
        project::Vector<project::List<KeyType>> table;
        Hash hash_fn;

        size_t get_index(const KeyType &key) const;
    };

    template <class KeyType, class Hash>
    HashSet<KeyType, Hash>::HashSet(size_t size)
        : table(size) {}

    template <class KeyType, class Hash>
    size_t HashSet<KeyType, Hash>::get_index(const KeyType &key) const
    {
        return hash_fn(key) % table.size();
    }

    template <class KeyType, class Hash>
    void HashSet<KeyType, Hash>::insert(const KeyType &key)
    {
        size_t index = get_index(key);
        for (const auto &element : table[index])
        {
            if (element == key)
            {
                throw Exception("Key already exists!");
            }
        }
        table[index].emplace_back(key);
    }

    template <class KeyType, class Hash>
    bool HashSet<KeyType, Hash>::find(const KeyType &key) const
    {
        size_t index = get_index(key);
        for (const auto &element : table[index])
        {
            if (element == key)
            {
                return true;
            }
        }
        return false;
    }

    template <class KeyType, class Hash>
    void HashSet<KeyType, Hash>::remove(const KeyType &key)
    {
        size_t index = get_index(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it)
        {
            if (*it == key)
            {
                table[index].erase(it);
                return;
            }
        }
    }
}
