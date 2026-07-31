#include <iostream>
#include <stack>
using namespace std;
// Here is the code and simpple explanation 
int main()
{
    stack<char> s;
    string str = "[()]";
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '{' || ch == '[' || ch == '(')
        {
            s.push(ch);
        }
        else
        {
            if (!s.empty())
            {
                char top = s.top();
                if ((ch == '}' && top == '{') || (ch == ']' && top == '[') || (ch == ')' && top == '('))
                {
                    s.pop();
                }
                else
                {
                    cout << "Unbalanced Parentheses" << endl;
                    return 0;
                }
            }
            else
            {
                cout << "Unbalanced Parentheses" << endl;
                return 0;
            }
        }
    }
    if (s.empty())
    {
        cout << "Balanced Parentheses" << endl;
    }
    else
    {
        cout << "Unbalanced Parentheses" << endl;
    }
}
// Problem Number 20 on leetcode
// difficulty : easy
// 📘 BalancedParentheses.cpp
// This program checks whether a given string of parentheses/brackets/braces
// is balanced using a stack.
//
// Concept:
//   - Balanced parentheses means every opening symbol '{', '[', '('
//     has a corresponding closing symbol '}', ']', ')' in the correct order.
//   - Example: "[()]" is balanced, but "[(" or "[(])" is not.
//
// Implementation details:
//   - Use a stack to store opening symbols.
//   - Traverse the string character by character:
//       * If it's an opening symbol → push onto the stack.
//       * If it's a closing symbol → check the stack:
//           - If stack is empty → unbalanced.
//           - If top of stack matches the closing symbol → pop it.
//           - Otherwise → unbalanced.
//   - After traversal:
//       * If stack is empty → balanced.
//       * If not empty → unbalanced.
//
// Example run with "[()]":
//   Step 1: '[' → push → stack = ['[']
//   Step 2: '(' → push → stack = ['[','(']
//   Step 3: ')' → matches '(' → pop → stack = ['[']
//   Step 4: ']' → matches '[' → pop → stack = []
//   End: stack empty → Balanced Parentheses
//
// ✅ Efficiency:
//   - Time Complexity: O(n) where n = length of string.
//   - Space Complexity: O(n) in worst case (all opening symbols).
