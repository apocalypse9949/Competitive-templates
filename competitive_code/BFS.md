# Breadth First Search (BFS)

## When to Use
- Finding the shortest path in an unweighted graph.
- Level order traversal of a tree.
- Exploring nodes layer by layer (e.g., minimum number of moves).

## Recognition Patterns
- "Minimum number of steps", "Shortest transformation sequence", "Level order of a binary tree".

## Core Idea
Use a queue to process nodes in FIFO order, marking visited nodes to avoid repeats.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

void bfs(int start, const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> dist(n, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    // dist array now holds shortest distances from start
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m; // nodes, edges
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v; // 0‑based indices
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(0, adj);
    return 0;
}
```

## Time Complexity
- `O(V + E)` – each vertex and edge visited once.

## Space Complexity
- `O(V)` for distance/visited array and queue.

## Common Variations
- Multi‑source BFS (push all sources initially).
- BFS on weighted graph with 0/1 weights (deque).
- BFS on a grid (use direction vectors).

## Common Mistakes
- Forgetting to mark a node visited when pushing to the queue (causes duplicates).
- Using recursion (stack overflow) instead of an explicit queue.
- Not handling disconnected components when needed.

## Dry Run Example
Graph: 0‑1, 0‑2, 1‑3, 2‑3.
- Start 0: distances → [0,1,1,2].

## Interview Tips
- Mention that BFS guarantees shortest path in unweighted graphs.
- Discuss using a `deque` for 0‑1 BFS.
- Explain how to adapt BFS for grid problems (boundary checks).

## Similar LeetCode Problems
- 102. Binary Tree Level Order Traversal
- 133. Word Ladder
- 1462. Course Schedule IV (reachability)
