# Tree

## When to Use
- Problems that involve hierarchical data structures (binary trees, N‑ary trees, tries).
- Need to perform traversals, compute depths, LCA, subtree queries, or dynamic programming on trees.

## Recognition Patterns
- "Serialize/deserialize a binary tree"
- "Find the lowest common ancestor"
- "Maximum path sum in a binary tree"

## Core Idea
Use recursion or an explicit stack/queue to traverse. For binary trees, often use depth‑first traversals (pre‑order, in‑order, post‑order). For level‑order, use BFS.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Example: inorder traversal (recursive)
void inorder(TreeNode* node, vector<int>& out) {
    if (!node) return;
    inorder(node->left, out);
    out.push_back(node->val);
    inorder(node->right, out);
}

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    // Build tree manually or via input parsing (omitted).
    // TreeNode* root = ...;
    // vector<int> result; inorder(root, result);
    return 0;}
```

## Time Complexity
- `O(N)` where N is the number of nodes (each visited once).

## Space Complexity
- `O(H)` recursion stack, where H is tree height (worst‑case O(N), balanced O(log N)).

## Common Variations
- Iterative DFS using a stack.
- BFS level order traversal.
- DFS with memoization for DP on trees.
- Trie for prefix problems.

## Common Mistakes
- Not handling null pointers before dereferencing.
- Forgetting to backtrack when using a global state in recursion.
- Assuming balanced height when recursion depth may hit stack limits.

## Dry Run Example
Tree:   1\n       / \\n      2   3
Inorder → 2 1 3.

## Interview Tips
- Explain recursion base case clearly.
- Mention iterative alternatives to avoid stack overflow.
- Discuss how to convert recursive to iterative using explicit stack.

## Similar LeetCode Problems
- 144. Binary Tree Preorder Traversal
- 98. Validate Binary Search Tree
- 124. Binary Tree Maximum Path Sum
