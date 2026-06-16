# Sliding Window

## When to Use
- Problems that require examining all contiguous subarrays or substrings of a certain size or satisfying a condition (e.g., longest substring with at most K distinct characters, minimum size subarray sum).

## Recognition Patterns
- "Find the smallest subarray with sum ≥ X", "Maximum length subarray with at most K distinct", "Count subarrays with sum <= T".

## Core Idea
Maintain a moving window `[l, r]` and adjust its bounds while preserving the invariant (e.g., sum, count of distinct elements). Expand `r` to include new elements, shrink `l` when the invariant is violated.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

// Example: minimum length subarray with sum >= target (positive numbers)
int minSubArrayLen(int target, const vector<int>& nums) {
    int n = nums.size();
    int best = n + 1; // answer / state
    int sum = 0; // current window sum
    int l = 0; // left pointer
    for (int r = 0; r < n; ++r) { // right pointer – process current element
        sum += nums[r]; // update answer / state
        while (sum >= target) { // move pointers
            best = min(best, r - l + 1); // update answer
            sum -= nums[l++]; // shrink window – move pointer
        }
    }
    return (best == n + 1) ? 0 : best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int target; cin >> target;
    int n; cin >> n; vector<int>a(n);
    for(int &x:a)cin>>x;
    cout << minSubArrayLen(target, a) << '\n';
    return 0;
}
```

## Time Complexity
`O(N)` – each element enters and leaves the window at most once.

## Space Complexity
`O(1)` additional.

## Common Variations
- Variable‑size windows (e.g., at most K distinct characters).
- Fixed‑size windows for sliding‑average or maximum.
- Using a frequency map or `unordered_map` for character counts.

## Common Mistakes
- Forgetting to shrink the window correctly leading to infinite loops.
- Using `while` instead of `if` when the condition should be checked only once per expansion.
- Not handling empty input or target larger than total sum.

## Dry Run Example
`target=7, nums=[2,3,1,2,4,3]`
- Expand → sum=2,3,6,… when sum≥7 shrink → best length becomes 2 (subarray `[4,3]`).

## Interview Tips
- State the invariant clearly before coding.
- Mention that for non‑positive numbers the simple two‑pointer technique may fail; fallback to prefix‑sum + binary search.
- Discuss trade‑offs between using a hashmap (O(1) average) vs. array for character frequencies.

## Similar LeetCode Problems
1. 209. Minimum Size Subarray Sum
2. 3. Longest Substring Without Repeating Characters
3. 713. Subarray Product Less Than K
```
