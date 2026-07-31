#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> q;
    q.push(23);
    q.push(14);
    q.push(20);
    q.push(18); // Adds an element in the Queue
    q.pop();    // Removes an element from Queue
    // Printing all element of Queue
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}
// 📘 QueueExample.cpp
// This program demonstrates the basic operations of a queue in C++.
// A queue is a linear data structure that follows FIFO (First In, First Out).
//
// Concept:
//   - Elements are added at the back (push).
//   - Elements are removed from the front (pop).
//   - The element at the front can be accessed using front().
//   - The queue becomes empty when all elements are removed.
//
// Implementation details:
//   - q.push(x): Adds element x to the back of the queue.
//   - q.pop(): Removes the element at the front of the queue.
//   - q.front(): Returns the element at the front.
//   - q.empty(): Checks if the queue is empty.
//
// Example run:
//   Initial queue after pushes → [23, 14, 20, 18]
//   q.pop() → removes 23 → [14, 20, 18]
//   Printing elements:
//       front=14 → print → pop → [20, 18]
//       front=20 → print → pop → [18]
//       front=18 → print → pop → []
//   Output: 14 20 18
//
// ✅ Efficiency:
//   - All operations (push, pop, front, empty) run in O(1) time.
