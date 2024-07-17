#include <iostream>

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

#include <iostream>
#include <limits>

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
                            tree.inorder();
                            break;
                        }
                        case 5:
                        {
                            tree.preorder();
                            break;
                        }
                        case 6:
                        {
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
                    break;
                }
                case 4:
                {
                    break;
                }
                case 5:
                {
                    break;
                }
                case 6:
                {
                    break;
                }
                case 7:
                {
                    break;
                }
                case 8:
                {
                    break;
                }
                case 9:
                {
                    break;
                }
                case 10:
                {
                    break;
                }
                case 11:
                {
                    break;
                }
                case 12:
                    exit_2 = true;
                    break;
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
            std::cout << "1. Linear Search\n"
                         "2. Iterative Binary Search\n"
                         "3. Recursive Binary Search\n"
                         "4. Two Pointer Search\n"
                         "5. Kadane's Algorithm (Maximum Subarray Problem)\n"
                         "6. Back to main menu\n"
                         "7. Bubble Sort\n"
                         "8. Selection Sort\n"
                         "9. Insertion Sort\n"
                         "10. Quick Sort\n"
                         "11. Merge Sort\n"
                         "12. Shell Sort\n"
                         "13. Hibbard Sort\n"
                         "14. Back\n";
            std::cout << "> ";
            std::cin >> choice;
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
