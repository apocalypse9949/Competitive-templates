# Design

## When to Use
- Problems that require designing a class, system, or API (e.g., implementing an LRU cache, iterator, or data structure).

## Recognition Patterns
- "Design a data structure that supports ...", "Implement a class with O(1) get/put", "Create an iterator for ...".

## Core Idea
Define clear interfaces, encapsulate state, and ensure each operation meets the required time/space guarantees.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

// Example: LRU Cache with O(1) get/put
class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        // update answer / state
        auto it = mp.find(key);
        if (it == mp.end()) return -1;
        // move node to front (most recent)
        dq.erase(it->second.second);
        dq.push_front(key);
        it->second.second = dq.begin(); // move pointers
        return it->second.first;
    }

    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            // update existing
            dq.erase(it->second.second);
        } else if ((int)mp.size() == cap) {
            // evict least recent
            int old = dq.back(); // process current element
            dq.pop_back(); // move pointers
            mp.erase(old);
        }
        dq.push_front(key); // update answer / state
        mp[key] = {value, dq.begin()}; // process current element
    }

private:
    int cap;
    list<int> dq; // order of usage
    unordered_map<int, pair<int, list<int>::iterator>> mp; // key -> {value, iterator in list}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // placeholder for interactive testing
    return 0;
}
```

## Time Complexity
`O(1)` average for `get` and `put`.

## Space Complexity
`O(capacity)`.

## Common Variations
- Design stack with max/min retrieval.
- Implement iterator for a binary tree (in‑order).
- Design a thread‑safe queue.

## Common Mistakes
- Forgetting to update both map and list on every operation.
- Not handling capacity zero.
- Memory leaks if raw pointers used.

## Dry Run Example
Operations: `put(1,1)`, `put(2,2)`, `get(1)` → returns 1 and moves key 1 to front.

## Interview Tips
- State the invariants of your data structure clearly.
- Explain why each operation meets the complexity.
- Discuss thread‑safety only if asked.

## Similar LeetCode Problems
1. 146. LRU Cache
2. 155. Min Stack
3. 380. Insert Delete GetRandom O(1)
```
