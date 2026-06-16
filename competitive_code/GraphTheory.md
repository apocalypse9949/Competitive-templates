# Graph Theory

## When to Use
- Problems that involve vertices and edges, connectivity, traversal, cycles, shortest paths, or spanning structures.

## Recognition Patterns
- "Find number of connected components", "Check if graph is bipartite", "Count paths of length K", "Detect cycle".

## Core Idea
Represent the graph using adjacency list (or matrix). Use DFS/BFS to explore, maintain visited array, and optionally store additional state (parent, distance, color).

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; // vertices, edges
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;++i){
        int u,v; cin>>u>>v; // process current element
        adj[u].push_back(v); // update answer / state
        adj[v].push_back(u); // undirected graph (remove for directed)
    }
    vector<int> visited(n+1,0);
    function<void(int)> dfs = [&](int u){
        visited[u]=1; // move pointers (mark visited)
        for(int v:adj[u]) if(!visited[v]) dfs(v); // recurse / move deeper
    };
    int components=0; // update answer / state
    for(int i=1;i<=n;++i){
        if(!visited[i]){ ++components; dfs(i); }
    }
    cout << components << '\n'; // output answer
    return 0;
}
```

## Time Complexity
`O(N + M)` – each vertex and edge visited once.

## Space Complexity
`O(N + M)` for adjacency list and visited array.

## Common Variations
- Directed graphs – use adjacency list without symmetric insertion.
- Weighted graphs – store pairs `{v, w}`.
- BFS for shortest unweighted paths, DFS for connectivity/acyclicity.

## Common Mistakes
- Forgetting to clear adjacency list between test cases.
- Using recursion on deep graphs → stack overflow; switch to iterative stack.
- Mixing 0‑based and 1‑based indexing.

## Dry Run Example
`n=4, edges={(1,2),(2,3)}` → components=2 ( {1,2,3} and {4} ).

## Interview Tips
- State whether graph is directed/undirected, weighted/unweighted.
- Mention need for `visited`/`color` arrays to avoid revisiting.
- For bipartite check, use two‑color BFS.

## Similar LeetCode Problems
1. 200. Number of Islands (grid → graph)
2. 261. Graph Valid Tree
3. 785. Is Graph Bipartite?
```
