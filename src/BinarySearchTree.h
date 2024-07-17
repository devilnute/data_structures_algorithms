#pragma once

#include <iostream>

namespace project
{
    template <class T>
    class Tree
    {
    public:
        Tree() : root_(nullptr) {}
        ~Tree() { destroy(root_); }

        void insert(const T &data);
        void remove(const T &key);
        bool find(const T &data);
        void preorder();
        void inorder();
        void postorder();

    private:
        struct Node
        {
            T data;
            Node *left;
            Node *right;

            Node(const T &val) : data(val), left(nullptr), right(nullptr) {}
        };

        Node *root_;

        Node *insertHelper(Node *node, const T &data);
        Node *deleteHelper(Node *node, const T &key);
        Node *findMin(Node *node);
        void destroy(Node *node);
        void preorderTraversal(Node *node);
        void inorderTraversal(Node *node);
        void postorderTraversal(Node *node);
    };

    template <class T>
    void Tree<T>::insert(const T &data)
    {
        root_ = insertHelper(root_, data);
    }

    template <class T>
    class Tree<T>::Node *Tree<T>::insertHelper(Node *node, const T &data)
    {
        if (node == nullptr)
        {
            return new Node(data);
        }
        else if (data < node->data)
        {
            node->left = insertHelper(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = insertHelper(node->right, data);
        }
        return node;
    }

    template <class T>
    void Tree<T>::remove(const T &key)
    {
        root_ = deleteHelper(root_, key);
    }

    template <class T>
    class Tree<T>::Node *Tree<T>::deleteHelper(Node *node, const T &key)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        else if (key < node->data)
        {
            node->left = deleteHelper(node->left, key);
        }
        else if (key > node->data)
        {
            node->right = deleteHelper(node->right, key);
        }
        else
        {
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            Node *temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteHelper(node->right, temp->data);
        }
        return node;
    }

    template <class T>
    class Tree<T>::Node *Tree<T>::findMin(Node *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    template <class T>
    bool Tree<T>::find(const T &data)
    {
        Node *current = root_;
        while (current != nullptr)
        {
            if (data == current->data)
            {
                return true;
            }
            else if (data < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        return false;
    }

    template <class T>
    void Tree<T>::preorder()
    {
        preorderTraversal(root_);
        std::cout << std::endl;
    }

    template <class T>
    void Tree<T>::preorderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            std::cout << node->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    template <class T>
    void Tree<T>::inorder()
    {
        inorderTraversal(root_);
        std::cout << std::endl;
    }

    template <class T>
    void Tree<T>::inorderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    template <class T>
    void Tree<T>::postorder()
    {
        postorderTraversal(root_);
        std::cout << std::endl;
    }

    template <class T>
    void Tree<T>::postorderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            std::cout << node->data << " ";
        }
    }

    template <class T>
    void Tree<T>::destroy(Node *node)
    {
        if (node != nullptr)
        {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }
}