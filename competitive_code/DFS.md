# Depth First Search (DFS)

## When to Use
- Traversing or exploring all nodes/edges of a graph/tree.
- Finding connected components, cycles, topological order (with post‑processing).

## Recognition Patterns
- "Given a graph, count islands", "Check if a path exists", "Detect cycle".

## Core Idea
Recursively (or with an explicit stack) visit a node, mark it visited, then explore its neighbours.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

// Graph as adjacency list
using Graph = vector<vector<int>>;

void dfs(int u, const Graph& g, vector<int>& visited) {
    // mark current node
    visited[u] = 1; // update answer / state
    // process current node (placeholder)
    // explore neighbours
    for (int v : g[u]) {
        if (!visited[v]) {
            dfs(v, g, visited); // move deeper
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; // n = vertices, m = edges
    cin >> n >> m;
    Graph g(n);
    for (int i=0;i<m;++i){
        int u,v;cin>>u>>v; // assuming 0‑based
        g[u].push_back(v);
        g[v].push_back(u); // omit for directed graph
    }
    vector<int> visited(n,0);
    // run DFS from every unvisited node (e.g., count components)
    for(int i=0;i<n;++i){
        if(!visited[i]){
            dfs(i,g,visited);
            // component found – update answer here
        }
    }
    return 0;
}
```

## Time Complexity
`O(V + E)` – each vertex and edge visited once.

## Space Complexity
`O(V)` recursion stack (or explicit stack) + adjacency list.

## Common Variations
- Recursive vs iterative stack implementation.
- Directed vs undirected graphs.
- Early exit when target found.
- Adding back‑tracking for path reconstruction.

## Common Mistakes
- Forgetting to mark a node before recursing → infinite recursion.
- Stack overflow on deep recursion (use iterative stack for large graphs).
- Mixing 0‑based and 1‑based indexing.

## Dry Run Example
Graph: 0‑1‑2 chain.
- start dfs(0): visit 0, recurse to 1, visit 1, recurse to 2, visit 2, return.
- visited = [1,1,1].

## Interview Tips
- Mention trade‑offs of recursion depth limits.
- Explain how to detect cycles (use parent tracking or colour array).
- For grid problems, treat each cell as a node and neighbours as 4‑direction moves.

## Similar LeetCode Problems
1. 200. Number of Islands
2. 207. Course Schedule
3. 131. Palindrome Partitioning (DFS backtracking)
```
