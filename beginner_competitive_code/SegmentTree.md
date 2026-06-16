# Segment Tree – Beginner Friendly

## When to Use
- Range queries (sum, min, max, gcd) with **point updates**.
- When you need `O(log N)` query and update on an array.

## Simple Idea
A segment tree is a binary tree where each node represents a segment (interval) of the array and stores the aggregated value for that segment.

## Basic C++ Code (C++17)
```cpp
struct SegTree {
    int n;                    // size of original array
    vector<long long> tree;   // 4 * n is enough
    SegTree(const vector<long long>& arr) { init(arr); }
    void init(const vector<long long>& arr) {
        n = (int)arr.size();
        tree.assign(4 * n, 0);
        build(1, 0, n - 1, arr);
    }
    void build(int node, int l, int r, const vector<long long>& arr) {
        if (l == r) { tree[node] = arr[l]; return; }
        int mid = (l + r) / 2;
        build(node * 2, l, mid, arr);
        build(node * 2 + 1, mid + 1, r, arr);
        tree[node] = tree[node * 2] + tree[node * 2 + 1]; // sum example
    }
    // point update: set arr[idx] = val
    void update(int idx, long long val) { update(1, 0, n - 1, idx, val); }
    void update(int node, int l, int r, int idx, long long val) {
        if (l == r) { tree[node] = val; return; }
        int mid = (l + r) / 2;
        if (idx <= mid) update(node * 2, l, mid, idx, val);
        else update(node * 2 + 1, mid + 1, r, idx, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
    // range query [ql, qr]
    long long query(int ql, int qr) { return query(1, 0, n - 1, ql, qr); }
    long long query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0; // no overlap
        if (ql <= l && r <= qr) return tree[node]; // total overlap
        int mid = (l + r) / 2;
        return query(node * 2, l, mid, ql, qr) + query(node * 2 + 1, mid + 1, r, ql, qr);
    }
};
```

## Time / Space Complexity
- **Build**: `O(N)`
- **Update**: `O(log N)`
- **Query**: `O(log N)`
- **Space**: `O(N)` (≈4N)

## Common Beginner Pitfalls
- Forgetting to make the tree **1‑based** for simplicity.
- Using `int` for sums that may overflow – use `long long`.
- Mixing up left/right child indices.

## Mini Dry‑Run Example
Array `[1,5,2,4]`
- Build creates nodes: root `[0‑3]` sum=12, left `[0‑1]` sum=6, right `[2‑3]` sum=6, …
- `query(1,2)` traverses left child `[0‑1]` (partial) and right child `[2‑3]` (partial) → returns `5+2=7`.

## Interview Tips
- Explain why segment tree is preferred over naive `O(N)` scans when there are many updates.
- Mention variations: **Lazy propagation** for range updates, **iterative bottom‑up** version for faster constants.
- Compare with **Fenwick Tree** – simpler but limited to prefix‑type queries.

## Related LeetCode Problems
- 307. Range Sum Query – Mutable
- 228. Summary Ranges (simple segment tree use case)
- 493. Reverse Pairs (requires BIT/segment tree)
- 1690. Stone Game VII (range sums)
```
