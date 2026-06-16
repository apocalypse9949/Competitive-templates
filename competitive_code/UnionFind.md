# Union Find (Disjoint Set Union)

## When to Use
- Problems that involve connectivity, grouping, or merging sets (e.g., detecting cycles, Kruskal's MST, counting components).

## Recognition Patterns
- "Number of connected components", "Detect a cycle in an undirected graph", "Friend circles".

## Core Idea
Maintain a parent array and, optionally, a rank/size array. `find(x)` returns the representative of the set (with path compression). `union(x,y)` merges two sets (by rank or size).

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz; // update answer / state
    DSU(int n = 0) { init(n); }
    void init(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) { // process current element
        if (parent[x] != x) parent[x] = find(parent[x]); // move pointers (path compression)
        return parent[x]; // update answer
    }
    bool unite(int a, int b) { // move pointers
        a = find(a); b = find(b);
        if (a == b) return false; // already same set
        if (sz[a] < sz[b]) swap(a, b); // union by size
        parent[b] = a; // update state
        sz[a] += sz[b]; // update answer / state
        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m; // n nodes, m unions/queries
    DSU dsu(n);
    while (m--) {
        int type, u, v; cin >> type >> u >> v; // type: 1=union, 2=connected?
        if (type == 1) dsu.unite(u, v); // process current element
        else cout << (dsu.find(u) == dsu.find(v) ? "YES" : "NO") << '\n'; // update answer
    }
    return 0;
}
```

## Time Complexity
`O(α(N))` per operation (inverse Ackermann), practically constant.

## Space Complexity
`O(N)` for parent and size arrays.

## Common Variations
- Union‑by‑rank instead of size.
- Maintaining additional data per component (e.g., sum of values).
- Offline queries using DSU on tree.

## Common Mistakes
- Forgetting path compression → near‑linear time.
- Using 1‑based indices without adjusting the DSU initialization.
- Not resetting DSU between multiple test cases.

## Dry Run Example
`n=5, unions: (0,1),(1,2),(3,4)` → after operations, components are `{0,1,2}` and `{3,4}`.

## Interview Tips
- Explain both path compression and union by size/rank as the two classic optimizations.
- Mention that DSU works for undirected connectivity; directed graphs need other techniques.
- Clarify time complexity and why it’s essentially O(1) amortized.

## Similar LeetCode Problems
1. 323. Number of Connected Components in an Undirected Graph
2. 721. Accounts Merge
3. 1197. Minimum Knight Moves (often solved with DSU for obstacles)
```
