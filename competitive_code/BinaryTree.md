# Binary Tree

## When to Use
- Problems that involve a binary tree data structure (not necessarily a BST) where each node has at most two children.

## Recognition Patterns
- "Maximum depth of binary tree", "Serialize/deserialize a binary tree", "Path sum".

## Core Idea
Traverse the tree (DFS/BFS) while maintaining state such as depth, sum, or parent pointers.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Example: preorder traversal collecting values
void preorder(TreeNode* node, vector<int>& out) {
    if (!node) return; // base case – update answer
    out.push_back(node->val); // process current element
    preorder(node->left, out); // move left
    preorder(node->right, out); // move right
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    TreeNode* root = nullptr; // build according to input spec
    vector<int> order;
    preorder(root, order);
    for (int v : order) cout << v << ' ';
    cout << '\n';
    return 0;
}
```

## Time Complexity
`O(N)` where N is number of nodes.

## Space Complexity
`O(H)` recursion stack (H = height) or `O(N)` if using an explicit stack.

## Common Variations
- Iterative traversal using a stack.
- Level order traversal (BFS) for breadth‑first problems.
- In‑order / post‑order for BST‑related queries.

## Common Mistakes
- Forgetting to check for `nullptr` before accessing children.
- Using global state that persists across multiple test cases.
- Confusing left/right order when problem requires specific traversal.

## Dry Run Example
Tree: `1` left=`2`, right=`3`.
- preorder: visit 1 → push 1, recurse left → push 2, recurse right → push 3 → output `1 2 3`.

## Interview Tips
- State the traversal method you’ll use before coding.
- Mention tail‑recursion optimization or converting to iterative to avoid stack overflow.
- Clarify whether the tree is balanced; for deep skewed trees consider iterative.

## Similar LeetCode Problems
1. 144. Binary Tree Preorder Traversal
2. 226. Invert Binary Tree
3. 102. Binary Tree Level Order Traversal
```
