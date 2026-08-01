// Here is the code and explanation
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> previousSmaller(vector<int> &arr)
    {
        stack<int> s;
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++)
        {
            while (!s.empty() && s.top() >= arr[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(s.top());
            }
            s.push(arr[i]);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> arr = {4, 1, 0, 8, 6};
    vector<int> ans = s.previousSmaller(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}

// 📘 PreviousSmaller.cpp
// This program finds the "previous smaller element" for each item in an array.
// For every element arr[i], it looks to the left and finds the nearest element
// that is smaller than arr[i]. If no such element exists, it returns -1.
//
// 🔑 Concept:
//   - Use a stack to keep track of potential "previous smaller" elements.
//   - As we iterate through the array:
//       * Pop elements from the stack until the top is smaller than arr[i].
//       * If the stack becomes empty → no smaller element exists → push -1.
//       * Otherwise, the top of the stack is the previous smaller element.
//       * Finally, push arr[i] onto the stack for future comparisons.
//
// ✅ Example Walkthrough (arr = [4, 1, 0, 8, 6]):
//   i=0 → 4 → stack empty → ans = [-1], stack = [4]
//   i=1 → 1 → pop(4) → stack empty → ans = [-1, -1], stack = [1]
//   i=2 → 0 → pop(1) → stack empty → ans = [-1, -1, -1], stack = [0]
//   i=3 → 8 → top=0 (smaller) → ans = [-1, -1, -1, 0], stack = [0,8]
//   i=4 → 6 → pop(8), top=0 (smaller) → ans = [-1, -1, -1, 0, 0], stack = [0,6]
//
// Output: -1 -1 -1 0 0
//
// ⚡ Efficiency:
//   - Each element is pushed and popped at most once.
//   - Time Complexity: O(n)
//   - Space Complexity: O(n) for the stack.
