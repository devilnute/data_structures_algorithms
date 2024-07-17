#include <iostream>
#include <queue>

#include "MyStack.h"

#include "PriorityQueue.h"

int main()
{
    project::Stack<int> st;

    project::PriorityQueue<int> q;

    q.push(1);
    q.push(423);
    q.push(2);

    std::cout << q.top();
    

    return 0;
}
