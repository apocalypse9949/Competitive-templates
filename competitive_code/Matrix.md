# Matrix

## When to Use
- Problems dealing with 2‑D grids, matrices, or board‑like structures where you need to traverse rows and columns.

## Recognition Patterns
- "Number of islands", "Rotate image", "Shortest path in a grid", "Spiral order".

## Core Idea
Treat each cell as a node; iterate using nested loops or BFS/DFS on the 2‑D array. Use direction vectors for neighbour moves.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; // rows, cols
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];

    // direction vectors for 4‑direction moves
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    // example: count connected components (DFS)
    vector<vector<int>> vis(n, vector<int>(m, 0));
    function<void(int,int)> dfs = [&](int x, int y){
        vis[x][y] = 1; // update answer / state
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]==1) {
                dfs(nx, ny); // move deeper
            }
        }
    };

    int components = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (!vis[i][j] && grid[i][j]==1) {
                ++components; // update answer
                dfs(i,j);
            }
    cout << components << '\n';
    return 0;
}
```

## Time Complexity
`O(n*m)` – each cell visited at most once.

## Space Complexity
`O(n*m)` for visited array (or `O(min(n,m))` for recursion stack).

## Common Variations
- 8‑direction moves.
- BFS for shortest path (use queue).
- In‑place transformation (rotate, flip).

## Common Mistakes
- Not checking bounds correctly.
- Forgetting to mark visited before recursing → stack overflow.
- Using recursion on large grids (use iterative stack).

## Dry Run Example
Input 3x3 grid:
```
1 0 1
1 1 0
0 0 1
```
Components counted = 2.

## Interview Tips
- Clarify whether diagonal connections count.
- Mention space‑optimized visited using the grid itself (e.g., set to -1).
- Discuss time‑space trade‑offs for BFS vs DFS.

## Similar LeetCode Problems
1. 200. Number of Islands
2. 54. Spiral Matrix
3. 48. Rotate Image
```
