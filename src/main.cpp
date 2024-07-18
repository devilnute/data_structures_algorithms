#include <iostream>
#include <limits>
#include <sstream>

#include "BinarySearchTree.h"
#include "ForwardList.h"
#include "HashMap.h"
#include "HashSet.h"
#include "MyQueue.h"
#include "MyStack.h"
#include "PriorityQueue.h"
#include "RingBuffer.h"
#include "SearchAlgorithms.h"
#include "SortingAlgorithms.h"
#include "StaticArray.h"
#include "Timer.h"

int main()
{
    size_t choice;
    bool exit = false;

    while (!exit)
    {
        std::cout << "1. Data Structures\n"
                  << "2. Algorithms\n"
                  << "3. Exit\n"
                  << "> ";
        std::cin >> choice;
        if (std::cin.eof())
        {
            std::cout << '\n';
            exit = true;
            break;
        }
        bool exit_2 = false;
        switch (choice)
        {
        case 1:
        {
            while (!exit_2)
            {
                std::cout << "1. Binary Search Tree\n"
                             "2. Doubly Linked List\n"
                             "3. Dynamic Array\n"
                             "4. Forward List\n"
                             "5. Hash Map\n"
                             "6. Hash Set\n"
                             "7. Deque\n"
                             "8. Queue\n"
                             "9. Stack\n"
                             "10. Priority Queue\n"
                             "11. Ring Buffer\n"
                             "12. Back\n"
                             "> ";
                std::cin >> choice;
                if (std::cin.eof())
                {
                    std::cout << '\n';
                    exit_2 = true;
                    exit = true;
                    break;
                }
                bool exit_3 = false;
                switch (choice)
                {
                case 1:
                {
                    project::Tree<int> tree;
                    std::cout << "Tree created\n";
                    while (!exit_3)
                    {
                        std::cout << "1. Insert key\n"
                                     "2. Remove key\n"
                                     "3. Find key\n"
                                     "4. Inorder traversal\n"
                                     "5. Preorder traversal\n"
                                     "6. Postorder traversal\n"
                                     "7. Back\n"
                                     "> ";
                        std::cin >> choice;
                        if (std::cin.eof())
                        {
                            std::cout << '\n';
                            exit_3 = true;
                            exit_2 = true;
                            exit = true;
                            break;
                        }
                        switch (choice)
                        {
                        case 1:
                        {
                            int e = 0;
                            std::cout << "> ";
                            std::cin >> e;
                            if (std::cin.fail())
                            {
                                std::cout << "Invalid argument\n";
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            else
                            {
                                tree.insert(e);
                            }
                            break;
                        }
                        case 2:
                        {
                            int e = 0;
                            std::cout << "> ";
                            std::cin >> e;
                            if (std::cin.fail())
                            {
                                std::cout << "Invalid argument\n";
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            else
                            {
                                if (!tree.find(e))
                                {
                                    std::cout << "Element not found\n";
                                }
                                else
                                {
                                    tree.remove(e);
                                }
                            }
                            break;
                        }
                        case 3:
                        {
                            int e = 0;
                            std::cout << "> ";
                            std::cin >> e;
                            if (std::cin.fail())
                            {
                                std::cout << "Invalid argument\n";
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            else
                            {
                                tree.find(e);
                                std::cout << "Element " << (tree.find(e) ? "" : "not ") << "found\n";
                            }
                            break;
                        }
                        case 4:
                        {
                            project::Timer t;
                            tree.inorder();
                            break;
                        }
                        case 5:
                        {
                            project::Timer t;
                            tree.preorder();
                            break;
                        }
                        case 6:
                        {
                            project::Timer t;
                            tree.postorder();
                            break;
                        }
                        case 7:
                        {
                            exit_3 = true;
                            break;
                        }
                        default:
                        {
                            std::cout << "Invalid choice, try again\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        }
                        }
                    }
                    break;
                }
                case 2:
                {
                    project::List<int> list;
                    std::cout << "List created\n";
                    while (!exit_3)
                    {
                        std::cout << "1. Push front\n"
                                     "2. Push back\n"
                                     "3. Pop front\n"
                                     "4. Pop back\n"
                                     "5. Print list\n"
                                     "6. Print size\n"
                                     "7. Back\n"
                                     "> ";
                        std::cin >> choice;
                        if (std::cin.eof())
                        {
                            std::cout << '\n';
                            exit_3 = true;
                            exit_2 = true;
                            exit = true;
                            break;
                        }
                        switch (choice)
                        {
                        case 1:
                        {
                            int e = 0;
                            std::cout << "> ";
                            std::cin >> e;
                            if (std::cin.fail())
                            {
                                std::cout << "Invalid argument\n";
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            else
                            {
                                list.push_front(e);
                            }
                            break;
                        }
                        case 2:
                        {
                            int e = 0;
                            std::cout << "> ";
                            std::cin >> e;
                            if (std::cin.fail())
                            {
                                std::cout << "Invalid argument\n";
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            else
                            {
                                list.push_back(e);
                            }
                            break;
                        }
                        case 3:
                        {
                            if (!list.empty())
                            {
                                list.pop_front();
                            }

                            break;
                        }
                        case 4:
                        {
                            if (!list.empty())
                            {
                                list.pop_back();
                            }
                            break;
                        }
                        case 5:
                        {
                            if (!list.empty())
                            {
                                list.print();
                            }
                            break;
                        }
                        case 6:
                        {
                            std::cout << list.size() << '\n';
                            break;
                        }
                        case 7:
                        {
                            exit_3 = true;
                            break;
                            project::Timer t;
                        }
                        default:
                        {
                            std::cout << "Invalid choice, try again\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        }
                        }
                    }
                    break;
                }
                case 3:
                {
                    project::Vector<int> vector;
                    std::cout << "Vector created\n";
                    while (!exit_3)
                    {
                        std::cout << "1. Initialize\n"
                                     "2. Push back\n"
                                     "3. Pop back\n"
                                     "4. Print element\n"
                                     "5. Print vector\n"
                                     "6. Print size\n"
                                     "7. Back\n"
                                     "> ";
                        std::cin >> choice;
                        if (std::cin.eof())
                        {
                            std::cout << '\n';
                            exit_3 = true;
                            exit_2 = true;
                            exit = true;
                            break;
                        }
                        switch (choice)
                        {
                        case 1:
                        {
                            char line[1024];
                            std::cin.getline(line, 1024);
                            std::basic_istringstream<char> iss(line);
                            int e;
                            while (iss >> e)
                            {
                                vector.push_back(e);
                            }
                            break;
                        }
                        case 2:
                        {
                            int e = 0;
                            std::cout << "> ";
                            std::cin >> e;
                            if (std::cin.fail())
                            {
                                std::cout << "Invalid argument\n";
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            else
                            {
                                vector.push_back(e);
                            }
                            break;
                        }
                        case 3:
                        {
                            if (!vector.empty())
                            {
                                vector.pop_back();
                            }
                            break;
                        }
                        case 4:
                        {
                            int i = 0;
                            std::cout << "> ";
                            std::cin >> i;
                            if (std::cin.fail() || i >= vector.size() || i < 0)
                            {
                                std::cout << "Invalid argument\n";
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            else
                            {
                                std::cout << vector[i] << '\n';
                            }
                            break;
                        }
                        case 5:
                        {
                            if (!vector.empty())
                            {
                                vector.print();
                            }
                            break;
                        }
                        case 6:
                        {
                            std::cout << vector.size() << '\n';
                            break;
                        }
                        case 7:
                        {
                            exit_3 = true;
                            break;
                        }
                        default:
                        {
                            std::cout << "Invalid choice, try again\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        }
                        }
                    }
                    break;
                }
                case 4:
                {
                    project::ForwardList<int> list;
                    std::cout << "Forward List created\n";
                    while (!exit_3)
                    {
                        std::cout << "1. Push front\n"
                                     "2. Pop Front\n"
                                     "3. Print front\n"
                                     "4. Print list\n"
                                     "5. Print size\n"
                                     "6. Back\n"
                                     "> ";
                        std::cin >> choice;
                        if (std::cin.eof())
                        {
                            std::cout << '\n';
                            exit_3 = true;
                            exit_2 = true;
                            exit = true;
                            break;
                        }
                        switch (choice)
                        {
                        case 1:
                        {
                            int e = 0;
                            std::cout << "> ";
                            std::cin >> e;
                            if (std::cin.fail())
                            {
                                std::cout << "Invalid argument\n";
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            else
                            {
                                list.push_front(e);
                            }
                            break;
                        }
                        case 2:
                        {
                            if (!list.empty())
                            {
                                list.pop_front();
                            }
                            break;
                        }
                        case 3:
                        {
                            if (!list.empty())
                            {
                                std::cout << list.front() << '\n';
                            }
                            break;
                        }
                        case 4:
                        {
                            if (!list.empty())
                            {
                                list.print();
                            }
                            break;
                        }
                        case 5:
                        {
                            std::cout << list.size() << '\n';
                            break;
                        }
                        case 6:
                        {
                            exit_3 = true;
                            break;
                        }
                        default:
                        {
                            std::cout << "Invalid choice, try again\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        }
                        }
                    }
                    break;
                }
                case 5:
                {
                    project::HashMap<int, int> map;
                    std::cout << "Map (int, int) created\n";
                    while (!exit_3)
                    {
                        std::cout << "1. Insert\n"
                                     "2. Find\n"
                                     "3. Remove\n"
                                     "4. Print map\n"
                                     "5. Back\n"
                                     "> ";
                        std::cin >> choice;
                        if (std::cin.eof())
                        {
                            std::cout << '\n';
                            exit_3 = true;
                            exit_2 = true;
                            exit = true;
                            break;
                        }
                        switch (choice)
                        {
                        case 1:
                        {
                            int k;
                            std::cout << "> ";
                            std::cin >> k;
                            if (!std::cin.fail())
                            {
                                int v;
                                std::cout << "> ";
                                std::cin >> v;
                                if (std::cin.fail())
                                {
                                    std::cout << "Invalid argument\n";
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                }
                                else
                                {
                                    if (!map.find(k))
                                    {
                                        map.insert(k, v);
                                    }
                                }
                            }
                            else
                            {
                                std::cout << "Invalid argument\n";
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            break;
                        }
                        case 2:
                        {
                            int k;
                            std::cout << "> ";
                            std::cin >> k;
                            if (std::cin.fail())
                            {
                                std::cout << "Invalid argument\n";
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            else
                            {
                                std::cout << "Element " << (map.find(k) ? "" : "not ") << "found\n";
                            }
                            break;
                        }
                        case 3:
                        {
                            int k;
                            std::cout << "> ";
                            std::cin >> k;
                            if (std::cin.fail())
                            {
                                std::cout << "Invalid argument\n";
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            else
                            {
                                if (map.find(k))
                                {
                                    map.remove(k);
                                }
                            }
                            break;
                        }
                        case 4:
                        {
                            map.print();
                            break;
                        }
                        case 5:
                        {
                            exit_3 = true;
                            break;
                        }
                        default:
                        {
                            std::cout << "Invalid choice, try again\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        }
                        }
                    }
                    break;
                }
                case 6:
                {
                    project::HashSet<int> set;
                    std::cout << "Set (int) created\n";
                    while (!exit_3)
                    {
                        std::cout << "1. Insert\n"
                                     "2. Find\n"
                                     "3. Remove\n"
                                     "4. Print set\n"
                                     "5. Back\n"
                                     "> ";
                        std::cin >> choice;
                        if (std::cin.eof())
                        {
                            std::cout << '\n';
                            exit_3 = true;
                            exit_2 = true;
                            exit = true;
                            break;
                        }
                        switch (choice)
                        {
                        case 1:
                        {
                            int k;
                            std::cout << "> ";
                            std::cin >> k;
                            if (std::cin.fail())
                            {
                                std::cout << "Invalid argument\n";
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            else
                            {
                                if (!set.find(k))
                                {
                                    set.insert(k);
                                }
                            }
                            break;
                        }
                        case 2:
                        {
                            int k;
                            std::cout << "> ";
                            std::cin >> k;
                            if (std::cin.fail())
                            {
                                std::cout << "Invalid argument\n";
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            else
                            {
                                std::cout << "Element " << (set.find(k) ? "" : "not ") << "found\n";
                            }
                            break;
                        }
                        case 3:
                        {
                            int k;
                            std::cout << "> ";
                            std::cin >> k;
                            if (std::cin.fail())
                            {
                                std::cout << "Invalid argument\n";
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            else
                            {
                                if (set.find(k))
                                {
                                    set.remove(k);
                                }
                            }
                            break;
                        }
                        case 4:
                        {
                            set.print();
                            break;
                        }
                        case 5:
                        {
                            exit_3 = true;
                            break;
                        }
                        default:
                        {
                            std::cout << "Invalid choice, try again\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        }
                        }
                    }
                    break;
                }
                case 7:
                {
                    project::Deque<int> deque;
                    std::cout << "Deque created\n";
                    while (!exit_3)
                    {
                        std::cout << "1. Push front\n"
                                     "2. Push back\n"
                                     "3. Pop front\n"
                                     "4. Pop back\n"
                                     "5. Print deque\n"
                                     "6. Back\n"
                                     "> ";
                        std::cin >> choice;
                        if (std::cin.eof())
                        {
                            std::cout << '\n';
                            exit_3 = true;
                            exit_2 = true;
                            exit = true;
                            break;
                        }
                        switch (choice)
                        {
                        case 1:
                        {
                            int e = 0;
                            std::cout << "> ";
                            std::cin >> e;
                            if (std::cin.fail())
                            {
                                std::cout << "Invalid argument\n";
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            else
                            {
                                deque.push_front(e);
                            }
                            break;
                        }
                        case 2:
                        {
                            int e = 0;
                            std::cout << "> ";
                            std::cin >> e;
                            if (std::cin.fail())
                            {
                                std::cout << "Invalid argument\n";
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            else
                            {
                                deque.push_back(e);
                            }
                            break;
                        }
                        case 3:
                        {
                            if (!deque.empty())
                            {
                                deque.pop_front();
                            }
                            break;
                        }
                        case 4:
                        {
                            if (!deque.empty())
                            {
                                deque.pop_back();
                            }
                            break;
                        }
                        case 5:
                        {
                            if (!deque.empty())
                            {
                                deque.print();
                            }
                            break;
                        }
                        case 6:
                        {
                            exit_3 = true;
                            break;
                        }
                        default:
                        {
                            std::cout << "Invalid choice, try again\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        }
                        }
                    }
                    break;
                }
                case 8:
                {
                    project::Queue<int> queue;
                    std::cout << "Queue created\n";
                    while (!exit_3)
                    {
                        std::cout << "1. Push\n"
                                     "2. Pop\n"
                                     "3. Print front\n"
                                     "4. Print back\n"
                                     "5. Print queue\n"
                                     "6. Back\n"
                                     "> ";
                        std::cin >> choice;
                        if (std::cin.eof())
                        {
                            std::cout << '\n';
                            exit_3 = true;
                            exit_2 = true;
                            exit = true;
                            break;
                        }
                        switch (choice)
                        {
                        case 1:
                        {
                            int e;
                            std::cout << "> ";
                            std::cin >> e;
                            if (std::cin.fail())
                            {
                                std::cout << "Invalid argument\n";
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            else
                            {
                                queue.push(e);
                            }
                            break;
                        }
                        case 2:
                        {
                            if (!queue.empty())
                            {
                                queue.pop();
                            }
                            break;
                        }
                        case 3:
                        {
                            if (!queue.empty())
                            {
                                std::cout << queue.front() << '\n';
                            }
                            break;
                        }
                        case 4:
                        {
                            if (!queue.empty())
                            {
                                std::cout << queue.back() << '\n';
                            }
                            break;
                        }
                        case 5:
                        {
                            if (!queue.empty())
                            {
                                queue.print();
                            }
                            break;
                        }
                        case 6:
                        {
                            exit_3 = true;
                            break;
                        }
                        default:
                        {
                            std::cout << "Invalid choice, try again\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        }
                        }
                    }
                    break;
                }
                case 9:
                {
                    project::Stack<int> stack;
                    std::cout << "Stack created\n";
                    while (!exit_3)
                    {
                        std::cout << "1. Push\n"
                                     "2. Pop\n"
                                     "3. Print top\n"
                                     "4. Print stack\n"
                                     "5. Back\n"
                                     "> ";
                        std::cin >> choice;
                        if (std::cin.eof())
                        {
                            std::cout << '\n';
                            exit_3 = true;
                            exit_2 = true;
                            exit = true;
                            break;
                        }
                        switch (choice)
                        {
                        case 1:
                        {
                            int e;
                            std::cout << "> ";
                            std::cin >> e;
                            if (std::cin.fail())
                            {

                                std::cout << "Invalid argument\n";
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            else
                            {
                                stack.push(e);
                            }
                            break;
                        }
                        case 2:
                        {
                            if (!stack.empty())
                            {
                                stack.pop();
                            }
                            break;
                        }
                        case 3:
                        {
                            if (!stack.empty())
                            {
                                std::cout << stack.top() << '\n';
                            }
                            break;
                        }
                        case 4:
                        {
                            if (!stack.empty())
                            {
                                stack.print();
                            }
                            break;
                        }
                        case 5:
                        {
                            exit_3 = true;
                            break;
                        }
                        default:
                        {
                            std::cout << "Invalid choice, try again\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        }
                        }
                    }
                    break;
                }
                case 10:
                {
                    project::PriorityQueue<int> preque;
                    std::cout << "Priority Queue created\n";
                    while (!exit_3)
                    {
                        std::cout << "1. Push\n"
                                     "2. Pop\n"
                                     "3. Print top\n"
                                     "4. Print queue\n"
                                     "5. Back\n"
                                     "> ";
                        std::cin >> choice;
                        if (std::cin.eof())
                        {
                            std::cout << '\n';
                            exit_3 = true;
                            exit_2 = true;
                            exit = true;
                            break;
                        }
                        switch (choice)
                        {
                        case 1:
                        {
                            int e;
                            std::cout << "> ";
                            std::cin >> e;
                            if (std::cin.fail())
                            {

                                std::cout << "Invalid argument\n";
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            else
                            {
                                preque.push(e);
                            }
                            break;
                        }
                        case 2:
                        {
                            if (!preque.empty())
                            {
                                preque.pop();
                            }
                            break;
                        }
                        case 3:
                        {
                            if (!preque.empty())
                            {
                                std::cout << preque.top() << '\n';
                            }
                            break;
                        }
                        case 4:
                        {
                            if (!preque.empty())
                            {
                                preque.print();
                            }
                            break;
                        }
                        case 5:
                        {
                            exit_3 = true;
                            break;
                        }
                        default:
                        {
                            std::cout << "Invalid choice, try again\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        }
                        }
                    }
                    break;
                }
                case 11:
                {
                    project::RingBuffer<int> buffer(10);
                    std::cout << "Ring Buffer created\n"
                                 "Size: 10\n";
                    while (!exit_3)
                    {
                        std::cout << "1. Write\n"
                                     "2. Read\n"
                                     "3. Back\n"
                                     "> ";
                        std::cin >> choice;
                        if (std::cin.eof())
                        {
                            std::cout << '\n';
                            exit_3 = true;
                            exit_2 = true;
                            exit = true;
                            break;
                        }
                        switch (choice)
                        {
                        case 1:
                        {
                            int e;
                            std::cout << "> ";
                            std::cin >> e;
                            if (std::cin.fail())
                            {

                                std::cout << "Invalid argument\n";
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            else
                            {
                                if (!buffer.isFull())
                                {
                                    buffer.write(e);
                                }
                                else
                                {
                                    std::cout << "Buffer is full\n";
                                }
                            }
                            break;
                        }
                        case 2:
                        {
                            if (!buffer.isEmpty())
                            {
                                std::cout << buffer.read() << '\n';
                            }
                            else
                            {
                                std::cout << "Buffer is empty" << '\n';
                            }
                            break;
                        }
                        case 3:
                        {
                            exit_3 = true;
                            break;
                        }
                        default:
                        {
                            std::cout << "Invalid choice, try again\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        }
                        }
                    }
                    break;
                }
                case 12:
                {
                    exit_2 = true;
                    break;
                }
                default:
                {
                    std::cout << "Invalid choice, try again\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                }
            }
            break;
        }
        case 2:
        {
            while (!exit_2)
            {
                std::cout << "1. Linear Search\n"
                             "2. Iterative Binary Search\n"
                             "3. Recursive Binary Search\n"
                             "4. Two Pointer Search\n"
                             "5. Kadane's Algorithm (Maximum Subarray Problem)\n"
                             "6. Bubble Sort\n"
                             "7. Selection Sort\n"
                             "8. Insertion Sort\n"
                             "9. Quick Sort\n"
                             "10. Merge Sort\n"
                             "11. Shell Sort\n"
                             "12. Hibbard Sort\n"
                             "13. Back\n";
                std::cout << "> ";
                std::cin >> choice;
                if (std::cin.eof())
                {
                    std::cout << '\n';
                    exit = true;
                    exit_2 = true;
                    break;
                }
                bool exit_3 = false;
                switch (choice)
                {
                case 1:
                {
                    int *nums;
                    size_t size;
                    std::cout << "Enter size of array: ";
                    std::cin >> size;
                    if (!std::cin.fail())
                    {
                        nums = new int[size];
                        std::cout << "Enter numbers, separated by enter:\n";
                        for (size_t i = 0; i < size; ++i)
                        {
                            std::cout << "> ";
                            std::cin >> nums[i];
                            if (std::cin.fail())
                            {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                --i;
                            }
                        }

                        if (!project::isOrdered(nums, size))
                        {
                            project::mergeSort(nums, size);
                            std::cout << "Array sorted\n";
                        }

                        int e;
                        std::cout << "Enter required number:\n"
                                     "> ";
                        std::cin >> e;
                        if (!std::cin.fail())
                        {
                            project::Timer t;
                            int *s = project::linearSearch(nums, size, e);
                            if (s)
                            {
                                std::cout << "Element " << *s << " found\n";
                            }
                            else
                            {
                                std::cout << "Element not found\n";
                            }
                        }
                        else
                        {
                            std::cout << "Invalid argument\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        delete[] nums;
                    }
                    else
                    {
                        std::cout << "Invalid argument\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    break;
                }
                case 2:
                {
                    int *nums;
                    size_t size;
                    std::cout << "Enter size of array: ";
                    std::cin >> size;
                    if (!std::cin.fail())
                    {
                        nums = new int[size];
                        std::cout << "Enter numbers, separated by enter:\n";
                        for (size_t i = 0; i < size; ++i)
                        {
                            std::cout << "> ";
                            std::cin >> nums[i];
                            if (std::cin.fail())
                            {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                --i;
                            }
                        }

                        if (!project::isOrdered(nums, size))
                        {
                            project::mergeSort(nums, size);
                            std::cout << "Array sorted\n";
                        }

                        int e;
                        std::cout << "Enter required number:\n"
                                     "> ";
                        std::cin >> e;
                        if (!std::cin.fail())
                        {
                            project::Timer t;
                            int *s = project::iterativeBinarySearch(nums, size, e);
                            if (s)
                            {
                                std::cout << "Element " << *s << " found\n";
                            }
                            else
                            {
                                std::cout << "Element not found\n";
                            }
                        }
                        else
                        {
                            std::cout << "Invalid argument\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        delete[] nums;
                    }
                    else
                    {
                        std::cout << "Invalid argument\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    break;
                }
                case 3:
                {
                    int *nums;
                    size_t size;
                    std::cout << "Enter size of array: ";
                    std::cin >> size;
                    if (!std::cin.fail())
                    {
                        nums = new int[size];
                        std::cout << "Enter numbers, separated by enter:\n";
                        for (size_t i = 0; i < size; ++i)
                        {
                            std::cout << "> ";
                            std::cin >> nums[i];
                            if (std::cin.fail())
                            {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                --i;
                            }
                        }

                        if (!project::isOrdered(nums, size))
                        {
                            project::mergeSort(nums, size);
                            std::cout << "Array sorted\n";
                        }

                        int e;
                        std::cout << "Enter required number:\n"
                                     "> ";
                        std::cin >> e;
                        if (!std::cin.fail())
                        {
                            project::Timer t;
                            int *s = project::recursiveBinarySearch(nums, size, e);
                            if (s)
                            {
                                std::cout << "Element " << *s << " found\n";
                            }
                            else
                            {
                                std::cout << "Element not found\n";
                            }
                        }
                        else
                        {
                            std::cout << "Invalid argument\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        delete[] nums;
                    }
                    else
                    {
                        std::cout << "Invalid argument\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    break;
                }
                case 4:
                {
                    int *nums;
                    size_t size;
                    std::cout << "Enter size of array: ";
                    std::cin >> size;
                    if (!std::cin.fail())
                    {
                        nums = new int[size];
                        std::cout << "Enter numbers, separated by enter:\n";
                        for (size_t i = 0; i < size; ++i)
                        {
                            std::cout << "> ";
                            std::cin >> nums[i];
                            if (std::cin.fail())
                            {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                --i;
                            }
                        }

                        if (!project::isOrdered(nums, size))
                        {
                            project::mergeSort(nums, size);
                            std::cout << "Array sorted\n";
                        }

                        int e;
                        std::cout << "Enter required sum:\n"
                                     "> ";
                        std::cin >> e;
                        if (!std::cin.fail())
                        {
                            project::Timer t;
                            std::pair<int *, int *> s = project::twoPointerSearch(nums, size, e);
                            if (s.first || s.second)
                            {
                                std::cout << "First: " << *s.first << '\n';
                                std::cout << "Second: " << *s.second << '\n';
                            }
                            else
                            {
                                std::cout << "Elements not found\n";
                            }
                        }
                        else
                        {
                            std::cout << "Invalid argument\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        delete[] nums;
                    }
                    else
                    {
                        std::cout << "Invalid argument\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    break;
                }
                case 5:
                {
                    int *nums;
                    size_t size;
                    std::cout << "Enter size of array: ";
                    std::cin >> size;
                    if (!std::cin.fail())
                    {
                        nums = new int[size];
                        std::cout << "Enter numbers, separated by enter:\n";
                        for (size_t i = 0; i < size; ++i)
                        {
                            std::cout << "> ";
                            std::cin >> nums[i];
                            if (std::cin.fail())
                            {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                --i;
                            }
                        }

                        if (!std::cin.fail())
                        {
                            project::Timer t;
                            std::pair<int *, int *> s = project::maximumSubarray(nums, size);
                            if (s.first || s.second)
                            {
                                std::cout << "First: " << *s.first << '\n';
                                std::cout << "Second: " << *s.second << '\n';
                            }
                            for (size_t i = 0; i < size; ++i)
                            {
                                std::cout << nums[i] << ' ';
                            }
                            std::cout << '\n';
                        }
                        else
                        {
                            std::cout << "Invalid argument\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        delete[] nums;
                    }
                    else
                    {
                        std::cout << "Invalid argument\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    break;
                }
                case 6:
                {
                    int *nums;
                    size_t size;
                    std::cout << "Enter size of array: ";
                    std::cin >> size;
                    if (!std::cin.fail())
                    {
                        nums = new int[size];
                        std::cout << "Enter numbers, separated by enter:\n";
                        for (size_t i = 0; i < size; ++i)
                        {
                            std::cout << "> ";
                            std::cin >> nums[i];
                            if (std::cin.fail())
                            {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                --i;
                            }
                        }

                        if (!std::cin.fail())
                        {
                            project::Timer t;
                            project::bubbleSort(nums, size);
                            std::cout << "Array sorted:\n";
                            for (size_t i = 0; i < size; ++i)
                            {
                                std::cout << nums[i] << ' ';
                            }
                            std::cout << '\n';
                        }
                        else
                        {
                            std::cout << "Invalid argument\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        delete[] nums;
                    }
                    else
                    {
                        std::cout << "Invalid argument\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    break;
                }
                case 7:
                {
                    int *nums;
                    size_t size;
                    std::cout << "Enter size of array: ";
                    std::cin >> size;
                    if (!std::cin.fail())
                    {
                        nums = new int[size];
                        std::cout << "Enter numbers, separated by enter:\n";
                        for (size_t i = 0; i < size; ++i)
                        {
                            std::cout << "> ";
                            std::cin >> nums[i];
                            if (std::cin.fail())
                            {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                --i;
                            }
                        }

                        if (!std::cin.fail())
                        {
                            project::Timer t;
                            project::selectionSort(nums, size);
                            std::cout << "Array sorted:\n";
                            for (size_t i = 0; i < size; ++i)
                            {
                                std::cout << nums[i] << ' ';
                            }
                            std::cout << '\n';
                        }
                        else
                        {
                            std::cout << "Invalid argument\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        delete[] nums;
                    }
                    else
                    {
                        std::cout << "Invalid argument\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    break;
                }
                case 8:
                {
                    int *nums;
                    size_t size;
                    std::cout << "Enter size of array: ";
                    std::cin >> size;
                    if (!std::cin.fail())
                    {
                        nums = new int[size];
                        std::cout << "Enter numbers, separated by enter:\n";
                        for (size_t i = 0; i < size; ++i)
                        {
                            std::cout << "> ";
                            std::cin >> nums[i];
                            if (std::cin.fail())
                            {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                --i;
                            }
                        }

                        if (!std::cin.fail())
                        {
                            project::Timer t;
                            project::insertionSort(nums, size);
                            std::cout << "Array sorted:\n";
                            for (size_t i = 0; i < size; ++i)
                            {
                                std::cout << nums[i] << ' ';
                            }
                            std::cout << '\n';
                        }
                        else
                        {
                            std::cout << "Invalid argument\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        delete[] nums;
                    }
                    else
                    {
                        std::cout << "Invalid argument\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    break;
                }
                case 9:
                {
                    int *nums;
                    size_t size;
                    std::cout << "Enter size of array: ";
                    std::cin >> size;
                    if (!std::cin.fail())
                    {
                        nums = new int[size];
                        std::cout << "Enter numbers, separated by enter:\n";
                        for (size_t i = 0; i < size; ++i)
                        {
                            std::cout << "> ";
                            std::cin >> nums[i];
                            if (std::cin.fail())
                            {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                --i;
                            }
                        }

                        if (!std::cin.fail())
                        {
                            project::Timer t;
                            project::quickSort(nums, size);
                            std::cout << "Array sorted:\n";
                            for (size_t i = 0; i < size; ++i)
                            {
                                std::cout << nums[i] << ' ';
                            }
                            std::cout << '\n';
                        }
                        else
                        {
                            std::cout << "Invalid argument\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        delete[] nums;
                    }
                    else
                    {
                        std::cout << "Invalid argument\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    break;
                }
                case 10:
                {
                    int *nums;
                    size_t size;
                    std::cout << "Enter size of array: ";
                    std::cin >> size;
                    if (!std::cin.fail())
                    {
                        nums = new int[size];
                        std::cout << "Enter numbers, separated by enter:\n";
                        for (size_t i = 0; i < size; ++i)
                        {
                            std::cout << "> ";
                            std::cin >> nums[i];
                            if (std::cin.fail())
                            {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                --i;
                            }
                        }

                        if (!std::cin.fail())
                        {
                            project::Timer t;
                            project::mergeSort(nums, size);
                            std::cout << "Array sorted:\n";
                            for (size_t i = 0; i < size; ++i)
                            {
                                std::cout << nums[i] << ' ';
                            }
                            std::cout << '\n';
                        }
                        else
                        {
                            std::cout << "Invalid argument\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        delete[] nums;
                    }
                    else
                    {
                        std::cout << "Invalid argument\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    break;
                }
                case 11:
                {
                    int *nums;
                    size_t size;
                    std::cout << "Enter size of array: ";
                    std::cin >> size;
                    if (!std::cin.fail())
                    {
                        nums = new int[size];
                        std::cout << "Enter numbers, separated by enter:\n";
                        for (size_t i = 0; i < size; ++i)
                        {
                            std::cout << "> ";
                            std::cin >> nums[i];
                            if (std::cin.fail())
                            {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                --i;
                            }
                        }

                        if (!std::cin.fail())
                        {
                            project::Timer t;
                            project::shellSort(nums, size);
                            std::cout << "Array sorted:\n";
                            for (size_t i = 0; i < size; ++i)
                            {
                                std::cout << nums[i] << ' ';
                            }
                            std::cout << '\n';
                        }
                        else
                        {
                            std::cout << "Invalid argument\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        delete[] nums;
                    }
                    else
                    {
                        std::cout << "Invalid argument\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    break;
                }
                case 12:
                {
                    int *nums;
                    size_t size;
                    std::cout << "Enter size of array: ";
                    std::cin >> size;
                    if (!std::cin.fail())
                    {
                        nums = new int[size];
                        std::cout << "Enter numbers, separated by enter:\n";
                        for (size_t i = 0; i < size; ++i)
                        {
                            std::cout << "> ";
                            std::cin >> nums[i];
                            if (std::cin.fail())
                            {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                --i;
                            }
                        }

                        if (!std::cin.fail())
                        {
                            project::Timer t;
                            project::hibbardSort(nums, size);
                            std::cout << "Array sorted:\n";
                            for (size_t i = 0; i < size; ++i)
                            {
                                std::cout << nums[i] << ' ';
                            }
                            std::cout << '\n';
                        }
                        else
                        {
                            std::cout << "Invalid argument\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        delete[] nums;
                    }
                    else
                    {
                        std::cout << "Invalid argument\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    break;
                }
                case 13:
                {
                    exit_2 = true;
                    break;
                }
                default:
                {
                    std::cout << "Invalid choice, try again\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                }
            }
            break;
        }
        case 3:
        {
            exit = true;
            std::cout << "Exiting the program...\n";
            break;
        }

        default:
        {
            std::cout << "Invalid choice, try again\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        }
    }

    return 0;
}
