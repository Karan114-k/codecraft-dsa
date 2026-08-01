#include <iostream>
#include <stack>
using namespace std;
class MyQueue
{
public:
    stack<int> s1;
    stack<int> s2;
    void push(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    void pop()
    {
        if (s1.empty())
        {
            cout << "Queue is Empty" << endl;
        }
        s1.pop();
    }
    int front()
    {
        return s1.top();
    }
    bool empty()
    {
        return s1.empty();
    }
};
int main()
{
    MyQueue q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    cout << q1.front() << endl;
    q1.pop();
    cout << q1.front() << endl;
    cout << q1.empty();
}

// This program demonstrates how to implement a Queue using two stacks (s1 and s2).
// Problem number : 232 on LeetCode
// 🔑 Concept:
//   - A Queue follows FIFO (First In, First Out).
//   - A Stack follows LIFO (Last In, First Out).
//   - By cleverly using two stacks, we can simulate
//     queue behavior.
//
// Implementation details:
//   - push(x):
//       * Move all elements from s1 to s2.
//       * Push x into s1.
//       * Move all elements back from s2 to s1.
//       * This ensures the front of the queue is always
//         at the top of s1.
//   - pop():
//       * Removes the front element (top of s1).
//       * If s1 is empty, print "Queue is Empty".
//   - front():
//       * Returns the front element (top of s1).
//   - empty():
//       * Returns true if s1 is empty, false otherwise.
//
// ✅ Example Walkthrough:
//   q1.push(1) → s1=[1]
//   q1.push(2) → s1=[1,2]
//   q1.push(3) → s1=[1,2,3]
//   front() → 1
//   pop() → removes 1 → s1=[2,3]
//   front() → 2
//   empty() → false
//
// Output:
//   1
//   2
//   0   (false → queue not empty)
//
// ⚡ Efficiency:
//   - push operation: O(n) (since elements are moved twice).
//   - pop/front/empty operations: O(1).
