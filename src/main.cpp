#include <iostream>
#include <queue>

#include "MyStack.h"

#include "PriorityQueue.h"
#include "RingBuffer.h"
#include "HashMap.h"
#include "HashSet.h"

int main()
{
    project::Stack<int> st;

    project::PriorityQueue<int> q;

    q.push(1);
    q.push(423);
    q.push(2);

    std::cout << q.top();

    project::RingBuffer<int> buf(3);

    buf.write(2);
    buf.write(3);
    buf.write(2123);

    buf.read();
    buf.read();
    buf.read();

    project::HashMap<int, const char *> map;

    project::HashSet<int> set;

    return 0;
}
