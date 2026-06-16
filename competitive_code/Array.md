# Array

## When to Use
- Problems that involve direct index access, traversal, or manipulation of elements in a contiguous block of memory.

## Recognition Patterns
- "Given an array of size n, find..."
- "Maximum/Minimum subarray", "Rotate array", "Find duplicate", etc.

## Core Idea
Iterate over the array while maintaining necessary state (e.g., prefix/suffix, running max/min, counters). Often can be combined with two‑pointer or sliding‑window techniques.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

// Template for typical array problems
int solve(const vector<int>& nums) {
    // Initialize answer and auxiliary variables
    int answer = 0; // placeholder for result
    // Example: running prefix sum
    long long prefix = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        // process current element
        int x = nums[i];
        // update answer / auxiliary state
        prefix += x;
        // ... your logic here ...
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> nums(n);
    for (int &x : nums) cin >> x;
    cout << solve(nums) << '\n';
    return 0;
}
```

## Time Complexity
`O(n)` – single pass over the array.

## Space Complexity
`O(1)` auxiliary space (excluding input storage).

## Common Variations
- Two‑pointer scans (e.g., moving window)
- Prefix/Suffix sums
- In‑place modifications (e.g., rotate, reverse)

## Common Mistakes
- Forgetting to handle integer overflow (use `long long`).
- Off‑by‑one index errors when accessing `i+1`.
- Modifying the input when it shouldn't be altered.

## Dry Run Example
Input: `[2, 1, 5, 3]`
- `i=0`: prefix=2
- `i=1`: prefix=3
- `i=2`: prefix=8
- `i=3`: prefix=11
(Explain how answer is computed based on the specific problem.)

## Interview Tips
- Clarify constraints (n up to 10⁵, value ranges).
- Mention edge cases: empty array, single element.
- Discuss trade‑offs between `O(n)` and `O(n log n)` solutions.

## Similar LeetCode Problems
1. 53. Maximum Subarray
2. 189. Rotate Array
3. 560. Subarray Sum Equals K
```
