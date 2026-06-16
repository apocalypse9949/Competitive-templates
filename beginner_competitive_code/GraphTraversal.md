# Graph Traversal – Beginner Friendly (BFS & DFS)

## When to Use
- Need to **visit every vertex** in a graph (connected components, shortest‑path in unweighted graph, topological ordering, cycle detection, etc.).
- The graph may be represented as **adjacency list** (preferred for sparse graphs) or **adjacency matrix**.

## Core Idea
- **BFS (Breadth‑First Search)** explores vertices level‑by‑level using a queue – ideal for shortest path in unweighted graphs.
- **DFS (Depth‑First Search)** explores as far as possible along each branch using recursion or an explicit stack – useful for connectivity, topological sort, and backtracking.

## BFS Template (C++17)
```cpp
vector<vector<int>> adj; // adjacency list, 0‑based
vector<int> bfs(int start) {
    int n = adj.size();
    vector<int> order; order.reserve(n);
    vector<bool> visited(n, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return order; // visitation order (or distances can be stored similarly)
}
```

## DFS Template (Recursive) (C++17)
```cpp
vector<vector<int>> adj; // adjacency list
vector<int> dfs(int start) {
    int n = adj.size();
    vector<int> order; order.reserve(n);
    vector<bool> visited(n, false);
    function<void(int)> dfsRec = [&](int u) {
        visited[u] = true;
        order.push_back(u);
        for (int v : adj[u]) {
            if (!visited[v]) dfsRec(v);
        }
    };
    dfsRec(start);
    return order;
}
```

## Iterative DFS (Stack) – avoids recursion depth limits
```cpp
vector<int> dfsIter(int start) {
    int n = adj.size();
    vector<int> order; order.reserve(n);
    vector<bool> visited(n, false);
    stack<int> st; st.push(start);
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (visited[u]) continue;
        visited[u] = true;
        order.push_back(u);
        // push children in reverse order to mimic recursive order
        for (auto it = adj[u].rbegin(); it != adj[u].rend(); ++it) {
            if (!visited[*it]) st.push(*it);
        }
    }
    return order;
}
```

## Common Pitfalls for Beginners
- Forgetting to **mark visited** before pushing onto the queue/stack – can lead to exponential revisits.
- Using recursion on very deep graphs (stack overflow). Use iterative version or increase recursion limit.
- Assuming the graph is **connected** – BFS/DFS starting from a single node only visits its component. Loop over all vertices to cover the whole graph.

## Mini Dry‑Run (BFS on simple graph)
Adjacency list:
```
0: [1,2]
1: [0,3]
2: [0]
3: [1]
```
`bfs(0)` order → `0,1,2,3` (level 0:0, level1:1,2, level2:3).

## Interview Tips
- Mention **time complexity** `O(V+E)` and **space** `O(V)` for both BFS and DFS.
- For **shortest path** in unweighted graph, BFS is the go‑to method.
- For **topological sort**, use DFS post‑order or Kahn’s algorithm (BFS variant).
- Explain how to detect **cycles** (BFS with parent tracking, DFS with recursion stack).

## Related LeetCode Problems
- 102. Binary Tree Level Order Traversal (BFS on tree)
- 133. Clone Graph (BFS/DFS traversal)
- 200. Number of Islands (BFS/DFS on grid)
- 207. Course Schedule (DFS for cycle detection)
```
