# Prefix Sum

## When to Use
- When you need fast range‑sum queries or cumulative aggregates over an array or matrix.

## Recognition Patterns
- "Sum of subarray [L,R]", "Range sum queries", "Number of subarrays with sum = K".

## Core Idea
Pre‑compute a `pref[i] = a[0] + … + a[i‑1]`. Any range sum `[L,R]` becomes `pref[R+1] - pref[L]` in O(1).

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<long long> buildPrefix(const vector<int>& a) {
    int n = a.size();
    vector<long long> pref(n+1, 0); // update answer / state
    for (int i = 0; i < n; ++i) {
        pref[i+1] = pref[i] + a[i]; // move pointers (cumulative)
    }
    return pref; // ready for queries
}

// example query function
long long rangeSum(const vector<long long>& pref, int L, int R) {
    // process current element
    return pref[R+1] - pref[L]; // update answer
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n; vector<int>a(n);
    for(int &x:a)cin>>x;
    auto pref = buildPrefix(a);
    int q; cin >> q;
    while(q--) {
        int L,R; cin>>L>>R; // assuming 0‑based inclusive
        cout << rangeSum(pref, L, R) << '\n'; // output answer
    }
    return 0;
}
```

## Time Complexity
`O(N)` to build, `O(1)` per query.

## Space Complexity
`O(N)` for the prefix array.

## Common Variations
- 2‑D prefix sums for sub‑matrix queries.
- Prefix sum with modulo for counting subarrays with specific remainder.
- Prefix XOR for XOR‑based problems.

## Common Mistakes
- Off‑by‑one errors when accessing `pref[R+1]`.
- Forgetting to use a larger type (`long long`) to avoid overflow.
- Not resetting the prefix array between test cases.

## Dry Run Example
Array `[1,2,3,4]` → `pref = [0,1,3,6,10]`. Query `[1,3]` → `pref[4]-pref[1]=10-1=9`.

## Interview Tips
- Mention that the prefix array is built once, then any number of range queries are O(1).
- For mutable arrays, discuss Fenwick/Segment Tree as dynamic alternatives.
- Clarify 0‑ vs 1‑based indexing for the problem.

## Similar LeetCode Problems
1. 303. Range Sum Query - Immutable
2. 560. Subarray Sum Equals K
3. 238. Product of Array Except Self (prefix‑suffix technique)
```
