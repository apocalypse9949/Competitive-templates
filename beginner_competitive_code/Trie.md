# Trie (Prefix Tree) – Beginner Friendly

## When to Use
- Fast lookup of **words or prefixes** in a large dictionary.
- Problems involving autocomplete, word search on a board, or counting distinct prefixes.

## Simple Idea
Each node stores an array (or map) of child pointers for each character and a flag indicating if a word ends here.

## Basic C++ Code (C++17)
```cpp
struct TrieNode {
    bool isEnd = false;
    array<TrieNode*, 26> child{}; // assumes lowercase a‑z
    TrieNode() { child.fill(nullptr); }
};

class Trie {
public:
    Trie() { root = new TrieNode(); }
    ~Trie() { clear(root); }
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->child[idx]) node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->isEnd = true;
    }
    bool search(const string& word) const {
        const TrieNode* node = findNode(word);
        return node && node->isEnd;
    }
    bool startsWith(const string& prefix) const {
        return findNode(prefix) != nullptr;
    }
private:
    TrieNode* root;
    TrieNode* findNode(const string& s) const {
        TrieNode* node = root;
        for (char c : s) {
            int idx = c - 'a';
            if (!node->child[idx]) return nullptr;
            node = node->child[idx];
        }
        return node;
    }
    void clear(TrieNode* node) {
        if (!node) return;
        for (TrieNode* nxt : node->child) clear(nxt);
        delete node;
    }
};
```

## Time / Space Complexity
- **Insert / Search / Prefix**: `O(L)` where `L` = length of the word/prefix.
- **Space**: `O(N * L * alphabet)` in worst case (but usually far less due to sharing prefixes).

## Common Beginner Mistakes
- Forgetting to initialize all child pointers to `nullptr`.
- Using `map<char, TrieNode*>` is safer for non‑a‑z alphabets but slower.
- Not handling the `isEnd` flag correctly – leads to false positives on prefixes.

## Dry‑Run Example
Insert "cat", "car", "dog".
- After inserting “cat”, path `c → a → t` marked `isEnd` at `t`.
- Inserting “car” re‑uses `c → a` then creates a new child `r`.
- Searching “ca” returns `false` for `search` but `true` for `startsWith`.

## Interview Tips
- Emphasize **O(L)** lookup versus **O(L * alphabet)** for array implementation.
- Mention memory‑saving alternatives: **compressed trie** (radix tree) or using `unordered_map` for sparse alphabets.
- Compare with **hash set** – trie gives prefix queries which hash cannot.

## Related LeetCode Problems
- 208. Implement Trie (Prefix Tree)
- 212. Word Search II
- 720. Longest Word in Dictionary
- 421. Maximum XOR of Two Numbers in an Array (often solved with bit‑trie)
```
