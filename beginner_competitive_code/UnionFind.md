# Disjoint Set Union (Union‑Find) – Beginner Friendly

## When to Use
- Finding connected components in an undirected graph.
- Handling equivalence relations, merging sets dynamically.
- Problems that require **offline** queries for connectivity.

## Core Idea
Maintain a parent array where each element points to its set representative (root). Use **path compression** on `find` and **union by rank/size** on `union` to keep operations near‑constant.

## Basic C++ Code (C++17)
```cpp
struct DSU {
    vector<int> parent, size;
    DSU(int n = 0) { init(n); }
    void init(int n) {
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    // Find with path compression
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    // Union by size
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false; // already same set
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
    // Check if two elements are in the same set
    bool same(int a, int b) { return find(a) == find(b); }
};
```

## Time / Space Complexity
- **Find / Union:** amortized `α(N)` ≈ `O(1)` (inverse Ackermann).
- **Space:** `O(N)` for `parent` and `size` arrays.

## Common Beginner Mistakes
- Forgetting to compress the path in `find` – leads to linear time on deep trees.
- Using **rank** incorrectly (should compare heights, not sizes).
- Off‑by‑one when indexing (0‑based vs 1‑based input).

## Mini Dry‑Run Example
```
N = 5, operations: union(0,1), union(2,3), union(1,2)
After first union: parent = [0,0,2,3,4]
After second:        parent = [0,0,2,2,4]
After third (union roots 0 and 2): parent = [0,0,0,0,4]
find(3) -> compresses path to 0.
```

## Interview Tips
- Mention both **path compression** and **union by size/rank** as the two optimizations.
- Explain why DSU is ideal for **Kruskal’s MST** and **offline connectivity** (e.g., queries sorted by weight).
- Compare with BFS/DFS for connectivity – DSU often simpler when many union operations.

## Related LeetCode Problems
- 200. Number of Islands (Union‑Find solution)
- 261. Graph Valid Tree
- 695. Max Area of Island (alternative DSU)
- 399. Evaluate Division (Union‑Find with weights – advanced)
```
