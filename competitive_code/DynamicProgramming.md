# Dynamic Programming (DP)

## When to Use
- Problems where the solution can be expressed in terms of solutions to sub‑problems with overlapping sub‑structures.
- Optimizing decisions over sequences, grids, subsets, or trees.

## Recognition Patterns
- "Maximum/Minimum ...", "Count number of ways", "Partition", "Knapsack", "Longest ... subsequence".

## Core Idea
Define a state representing a partial solution, derive a recurrence, and fill a DP table (iterative) or use memoized recursion.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

// Example: 1‑D DP for "Maximum Subarray Sum" (Kadane) – replace with your recurrence
int solve(const vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0); // dp[i] = best ending at i
    dp[0] = nums[0];
    int answer = dp[0];
    for (int i = 1; i < n; ++i) {
        // dp transition: either extend previous or start new
        dp[i] = max(nums[i], dp[i-1] + nums[i]); // update answer / state
        answer = max(answer, dp[i]);
    }
    return answer; // placeholder result
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n; vector<int>a(n); for(int &x:a)cin>>x;
    cout<<solve(a)<<"\n";
    return 0;
}
```

## Time Complexity
`O(n * state_dim)` – linear in the number of states (here `O(n)`).

## Space Complexity
`O(n)` for the DP table, can be reduced to `O(1)` if only previous row needed.

## Common Variations
- 2‑D DP (grid/path problems)
- DP on subsets (bitmask DP)
- DP on trees (post‑order traversal)
- Memoization with recursion (`unordered_map` for state -> value)

## Common Mistakes
- Forgetting to initialise base cases correctly.
- Over‑counting because of off‑by‑one in indices.
- Using `int` where values exceed 2³¹‑1 (`long long`).

## Dry Run Example
For `[-2,1,-3,4,-1,2,1,-5,4]` (Kadane):
- dp[0] = -2, answer = -2
- i=1: dp[1]=max(1, -2+1)=1, answer=1
- ... final answer = 6 (subarray `[4,-1,2,1]`).

## Interview Tips
- Start by writing the recurrence on paper before coding.
- Discuss space optimisation (rolling array) if asked.
- Mention time‑trade‑off for O(2ⁿ) vs DP.

## Similar LeetCode Problems
1. 53. Maximum Subarray
2. 198. House Robber
3. 322. Coin Change
```
