#include <iostream>
#include <stack>
using namespace std;
// Here is code and explaination( below the code )
class MinStack
{
private:
    stack<int> s;
    stack<int> minS;

public:
    void push(int x)
    {
        s.push(x);
        if (minS.empty() || x <= minS.top())
        {
            minS.push(x);
        }
    }

    void pop()
    {
        if (!s.empty())
        {
            if (s.top() == minS.top())
            {
                minS.pop();
            }
            s.pop();
        }
    }
    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return minS.top();
    }
};
int main()
{
    MinStack minStack;
    minStack.push(4);
    minStack.push(0);
    minStack.push(7);
    cout << "Minimum element: " << minStack.getMin() << endl;
    minStack.pop();
    cout << "Top element: " << minStack.top() << endl;
    cout << "Minimum element: " << minStack.getMin() << endl;
    return 0;
}

// 📘 MinStack.cpp
// This program demonstrates the MinStack data structure.
// A MinStack is a special type of stack that, in addition to
// standard operations (push, pop, top), can also return the
// minimum element in constant time (O(1)).
//
// Implementation details:
//   - Two stacks are used:
//       1. 's'    → stores all elements.
//       2. 'minS' → keeps track of the minimum values.
//   - Push(x):
//       Adds x to 's'. If 'minS' is empty or x <= minS.top(),
//       also push x onto 'minS'.
//   - Pop():
//       Removes the top element from 's'. If it equals minS.top(),
//       also pop from 'minS'.
//   - Top():
//       Returns the top element of 's'.
//   - GetMin():
//       Returns the top element of 'minS', which is always the
//       current minimum.
//
// ✅ Efficiency:
//   - All operations run in O(1) time.
//   - Extra space is used only when a new minimum is encountered.
//
// Example run:
//   push(4) → s=[4], minS=[4]
//   push(0) → s=[4,0], minS=[4,0]
//   push(7) → s=[4,0,7], minS=[4,0]
//   getMin() → 0
//   pop() → removes 7 → s=[4,0], minS=[4,0]
//   top() → 0
//   getMin() → 0
