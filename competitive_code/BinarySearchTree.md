# Binary Search Tree

## When to Use
- Problems that need ordered data with logarithmic insert, delete, search, or range queries (e.g., dynamic order statistics, predecessor/successor, balanced BST operations).

## Recognition Patterns
- "Insert, delete and find kth smallest", "Find lower/upper bound", "Range sum in a BST", "Validate BST".

## Core Idea
Implement a node structure with `val`, `left`, `right`. Optionally store extra metadata (size, sum) and keep the tree balanced (AVL, Red‑Black, Treap, Splay) for guaranteed `O(log N)` operations.

## Generic Template Code (C++17) – Treap (randomized BST)
```cpp
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int key, pri; // priority for heap property
    Node *l, *r;
    int sz; // subtree size – update answer / state
    Node(int k) : key(k), pri(rand()), l(nullptr), r(nullptr), sz(1) {}
};
int getSize(Node* t){ return t ? t->sz : 0; }
void upd(Node* t){ if(t) t->sz = 1 + getSize(t->l) + getSize(t->r); } // move pointers

// split by key <= x goes to left
void split(Node* t, int x, Node*& a, Node*& b){
    if(!t) a = b = nullptr; // base case
    else if(t->key <= x){
        split(t->r, x, t->r, b);
        a = t; // update answer
    } else {
        split(t->l, x, a, t->l);
        b = t; // update answer
    }
    upd(t);
}
Node* merge(Node* a, Node* b){
    if(!a||!b) return a?a:b; // move pointers
    if(a->pri > b->pri){
        a->r = merge(a->r, b);
        upd(a);
        return a;
    } else {
        b->l = merge(a, b->l);
        upd(b);
        return b;
    }
}

void insert(Node*& root, int key){
    Node *a, *b; split(root, key, a, b);
    root = merge(merge(a, new Node(key)), b); // update answer / state
}

bool exists(Node* t, int key){
    while(t){ // process current element
        if(t->key == key) return true; // answer found
        t = (key < t->key) ? t->l : t->r; // move pointers
    }
    return false;
}

int kth(Node* t, int k){ // 1‑based
    if(!t) return -1; // not found
    int left = getSize(t->l);
    if(k == left + 1) return t->key; // update answer
    if(k <= left) return kth(t->l, k); // move pointers
    return kth(t->r, k - left - 1); // move pointers
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Node* root = nullptr;
    int q; cin >> q;
    while(q--){
        string op; int x; cin >> op >> x; // process current element
        if(op == "insert") insert(root, x);
        else if(op == "find") cout << (exists(root, x) ? "YES" : "NO") << '\n';
        else if(op == "kth") cout << kth(root, x) << '\n';
    }
    return 0;
}
```

## Time Complexity
`O(log N)` expected per operation (insert, search, kth) due to random balancing.

## Space Complexity
`O(N)` for nodes.

## Common Variations
- AVL or Red‑Black trees for deterministic balancing.
- Augmenting nodes with subtree sum for range‑sum queries.
- Implicit treap for order‑statistics on arrays.

## Common Mistakes
- Forgetting to call `upd` after every structural change.
- Using `rand()` without seeding may produce deterministic but still balanced enough.
- Memory leaks – delete nodes if needed (not required for contest). 

## Dry Run Example
Insert `[5,2,8,1]` → tree built, `kth 2` returns `2`.

## Interview Tips
- Explain why balancing is needed (worst‑case `O(N)` for plain BST).
- Mention alternative balanced structures (std::set/multiset) for quick use.
- Clarify handling of duplicate keys (ignore or count occurrences).

## Similar LeetCode Problems
1. 701. Insert into a Binary Search Tree
2. 285. Inorder Successor in BST
3. 108. Convert Sorted Array to Binary Search Tree
```
