# Sorting

## When to Use
- Need to order elements to enable binary search, two‑pointer techniques, or satisfy problem constraints.
- Problems explicitly ask for the k‑th smallest/largest element or to group identical items.

## Recognition Patterns
- "Sort the array and then..."
- "Find the median/average after sorting"
- "Arrange items in non‑decreasing order"

## Core Idea
Choose an appropriate sorting algorithm (usually `std::sort` for O(N log N) average case). For linear‑time constraints, use counting/radix sort on integer ranges.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    // sort ascending
    sort(a.begin(), a.end()); // O(N log N)
    // use sorted array for further logic
    // ...
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
```

## Time Complexity
- `O(N log N)` for `std::sort` (introsort).
- `O(N + K)` for counting sort (`K` = range size).

## Space Complexity
- `O(1)` extra for in‑place `std::sort` (ignoring recursion stack).
- `O(K)` extra for counting/radix sort.

## Common Variations
- Stable sort (`stable_sort`).
- Custom comparator for descending or custom ordering.
- Counting sort / radix sort for bounded integer ranges.

## Common Mistakes
- Forgetting to use `long long` for large values.
- Sorting the wrong container (e.g., sorting a copy instead of the original).
- Ignoring stability when required.

## Dry Run Example
Input: `5 3 1 4 2`
- After `sort`: `1 2 3 4 5`
- Further steps can now rely on ordered indices.

## Interview Tips
- Mention `std::sort` complexity and that it’s usually sufficient.
- Discuss when linear‑time sorts are needed.
- Highlight stability considerations.

## Similar LeetCode Problems
- 912. Sort an Array
- 1636. Sort Array by Increasing Frequency
- 238. Product of Array Except Self (uses sorting for a variant solution)
