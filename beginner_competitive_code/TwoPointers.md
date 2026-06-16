# Two Pointers

## When to Use
- The problem involves finding pairs, subarrays, or windows that satisfy a condition with a monotonic property (e.g., sorted array, increasing sum).
- Typical for sorted arrays, strings, or sliding window problems.

## Recognition Patterns
- "Find if any two numbers sum to X"
- "Longest subarray with sum ≤ K"
- "Remove duplicates from a sorted array"

## Core Idea
Maintain two indices (left/right) that move towards each other or slide across the structure, adjusting based on the condition.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

// Example: check if there exists a pair with sum = target in a sorted array
bool twoSum(const vector<int>& a, int target) {
    int l = 0, r = (int)a.size() - 1;
    while (l < r) {
        long long sum = (long long)a[l] + a[r];
        if (sum == target) return true;
        if (sum < target) ++l; // need larger sum
        else --r;              // need smaller sum
    }
    return false;
}

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    int n, target; cin>>n>>target; vector<int>a(n); for(int &x:a)cin>>x; sort(a.begin(),a.end());
    cout << (twoSum(a,target) ? "YES" : "NO") << '\n';
    return 0;}
```

## Time Complexity
- `O(N)` after any required sorting (`O(N log N)`).

## Space Complexity
- `O(1)` extra.

## Common Variations
- Sliding window (right pointer only, left moves to maintain condition).
- Three‑pointer extensions for triplet problems.

## Common Mistakes
- Forgetting to sort the array when required.
- Using `<=` instead of `<` leading to infinite loops.

## Dry Run Example
Array `[1,2,4,5,6]`, target `9` → pointers move to `4+5=9` → return true.

## Interview Tips
- Explain why the pointers move in a particular direction.
- Mention handling of duplicates and when to use `while (l < r && a[l]==a[l-1]) ++l;` etc.

## Similar LeetCode Problems
- 167. Two Sum II – Input array is sorted
- 209. Minimum Size Subarray Sum
- 3. Longest Substring Without Repeating Characters (sliding window variant)
