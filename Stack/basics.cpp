#include <iostream>
#include <stack>
using namespace std;
int main()
{
    // Decleration of Stack 
    stack<int> s;
    // Adding an Element in Stack (called push operation)
    s.push(1);
    s.push(2);
    s.push(3);
    // Accessing top element of the Stack
    cout << "Top element is " << s.top() << endl;
    // Removing an element in Stack
    s.pop();
    cout << "Top element is " << s.top() << endl;
    // checking stack is empty or not
    if (s.empty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "There are some element in Stack. ";
    }
     
}
