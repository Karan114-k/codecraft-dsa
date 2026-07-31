#include <iostream>
#include <queue>
using namespace std;
// Here is the code and explanation 
class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;
    void push(int x)
    {
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack is Empty" << endl;
        }
        q1.pop();
    }
    int top()
    {
        return q1.front();
    }
    bool empty()
    {
        return q1.empty();
    }
};
int main()
{
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.empty();
}
// problem Number 225 on leetcode
// 📘 MyStack.cpp
// This program demonstrates how to implement a stack
// using two queues (q1 and q2).
//
// Concept:
//   - A stack follows LIFO (Last In, First Out).
//   - A queue follows FIFO (First In, First Out).
//   - By cleverly rearranging elements between two queues,
//     we can simulate stack behavior.
//
// Implementation details:
//   - push(x):
//       Move all elements from q1 to q2.
//       Push x into q1 (so it stays at the front).
//       Move all elements back from q2 to q1.
//       Result: newest element is always at the front of q1.
//   - pop():
//       Removes the front element of q1 (which is the stack's top).
//       If q1 is empty, print "Stack is Empty".
//   - top():
//       Returns the front element of q1 (the stack's top).
//   - empty():
//       Returns true if q1 is empty, false otherwise.
//
// ✅ Efficiency:
//   - push(x): O(n) because all elements are moved twice.
//   - pop(), top(), empty(): O(1).
//
// Example run:
//   push(1) → q1=[1]
//   push(2) → q1=[2,1]
//   push(3) → q1=[3,2,1]
//   top() → 3
//   pop() → removes 3 → q1=[2,1]
//   top() → 2
//   empty() → false
