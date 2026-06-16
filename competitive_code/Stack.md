# Stack

## When to Use
- Problems that require LIFO access, backtracking, or tracking previous states (e.g., expression evaluation, parentheses checking).

## Recognition Patterns
- "Validate parentheses", "Next greater element", "Evaluate postfix expression".

## Core Idea
Use `std::stack<T>` to push elements as you traverse and pop when needed. Often combined with a loop over the input.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

// Example: Next Greater Element
vector<int> nextGreater(const vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st; // stores indices
    for (int i = 0; i < n; ++i) {
        // process current element
        while (!st.empty() && nums[i] > nums[st.top()]) {
            ans[st.top()] = nums[i]; // update answer
            st.pop(); // move pointers
        }
        st.push(i); // push current index
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n; vector<int>a(n); for(int &x:a)cin>>x;
    auto res = nextGreater(a);
    for(int v:res) cout<<v<<' '; cout<<"\n";
    return 0;
}
```

## Time Complexity
`O(n)` – each element pushed and popped at most once.

## Space Complexity
`O(n)` worst‑case for the stack.

## Common Variations
- Monotonic stack for nearest greater/smaller.
- Stack of characters for expression validation.
- Using stack to simulate recursion.

## Common Mistakes
- Forgetting to clear the stack between test cases.
- Accessing `st.top()` when stack is empty.
- Mixing up indices vs. values.

## Dry Run Example
`[2,1,2,4,3]` → next greater → `[4,2,4,-1,4]`.

## Interview Tips
- Mention that stack operations are O(1) amortized.
- Explain why a monotonic stack works for range queries.
- Discuss edge cases: all decreasing sequence.

## Similar LeetCode Problems
1. 496. Next Greater Element I
2. 20. Valid Parentheses
3. 150. Evaluate Reverse Polish Notation
```
