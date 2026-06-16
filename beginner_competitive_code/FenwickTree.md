# Fenwick Tree (Binary Indexed Tree) – Beginner Friendly

## When to Use
- Need to query **prefix sums** or **range sums** repeatedly with updates.
- Works well for problems where you need `O(log N)` updates and queries on an array of numbers.

## Simple Explanation
A Fenwick Tree stores cumulative frequencies in a compact array. The index manipulation `i += i & -i` moves to the next responsible node, while `i -= i & -i` moves to the parent.

## Basic C++ Code (C++17)
```cpp
struct Fenwick {
    int n;                // size of original array
    vector<long long> bit; // 1‑based indexing
    Fenwick(int n = 0) { init(n); }
    void init(int n_) { n = n_; bit.assign(n + 1, 0); }
    // add value `val` at position `idx`
    void add(int idx, long long val) {
        for (++idx; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    // sum of [0, idx]
    long long sum(int idx) const {
        long long res = 0;
        for (++idx; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }
    // sum of [l, r]
    long long rangeSum(int l, int r) const { return sum(r) - sum(l - 1); }
};
```

## Time / Space Complexity
- **Update**: `O(log N)`
- **Query**: `O(log N)`
- **Space**: `O(N)`

## Common Pitfalls (Beginner)
- Forget to use **1‑based indexing** inside the tree.
- Off‑by‑one errors when converting between 0‑based array indices and Fenwick indices.
- Not initializing the `bit` vector to size `n+1`.

## Quick Dry‑Run Example
```text
Array: [3, 2, -1, 6]
Build Fenwick:
add(0,3) → bit[1]=3, bit[2]=3, bit[4]=3
add(1,2) → bit[2]=5, bit[4]=5
add(2,-1)→ bit[3]=-1, bit[4]=4
add(3,6) → bit[4]=10
```
`sum(2)` returns `3+2‑1 = 4`.

## Interview Tips
- Mention the relation to **Binary Indexed Tree** and why it’s better than a plain prefix sum array when many updates occur.
- Explain the `i & -i` trick clearly – it isolates the lowest set bit.
- Show a brief comparison with **Segment Tree** (Fenwick is simpler & uses less memory).

## Related LeetCode Problems
- 303. Range Sum Query – Immutable
- 307. Range Sum Query – Mutable
- 1695. Maximum Erasure Value
- 1735. Count Ways to Make Array Sum Equal to Target
```
