# Heap (Priority Queue) – Beginner Friendly

## When to Use
- Need to repeatedly retrieve the **maximum** or **minimum** element in a dynamic set.
- Problems that involve **k‑largest/k‑smallest**, merging sorted streams, or implementing Dijkstra’s algorithm.

## Core Idea
A binary heap is a complete binary tree where each parent satisfies the heap property:
- **Max‑heap:** `parent >= children`
- **Min‑heap:** `parent <= children`
The tree can be stored in an array for O(1) indexing.

## Basic C++ Code (C++17) using `priority_queue`
```cpp
#include <queue>
#include <vector>
using namespace std;

// Max‑heap (default)
priority_queue<int> maxHeap; // push, pop, top in O(log N)

// Min‑heap using greater comparator
priority_queue<int, vector<int>, greater<int>> minHeap;

void demo() {
    // Insert elements
    maxHeap.push(5);
    maxHeap.push(2);
    maxHeap.push(9);
    // Get max
    int mx = maxHeap.top(); // 9
    maxHeap.pop();

    // Min‑heap example
    minHeap.push(5);
    minHeap.push(2);
    minHeap.push(9);
    int mn = minHeap.top(); // 2
}
```

If you need a **custom comparator** (e.g., for pairs):
```cpp
struct Node { int dist; int id; };
struct Cmp { bool operator()(const Node& a, const Node& b) const {
    return a.dist > b.dist; // min‑heap by distance
}};
priority_queue<Node, vector<Node>, Cmp> pq;
```

## Time / Space Complexity
- **Insert / Push:** `O(log N)`
- **Extract / Pop:** `O(log N)`
- **Peek / Top:** `O(1)`
- **Space:** `O(N)` (stores all elements)

## Common Beginner Mistakes
- Assuming `pop()` returns the element – it only removes it. Use `top()` before `pop()`.
- Forgetting to include `<functional>` when using `greater<>` or custom comparators.
- Mixing up *max* vs *min* heap when the comparator is reversed.

## Mini Dry‑Run Example
Insert sequence `[4,1,7,3]` into a max‑heap:
- After 4: `[4]`
- After 1: `[4,1]`
- After 7: `[7,4,1]` (7 bubbles to root)
- After 3: `[7,4,1,3]`
`pop()` returns 7, heap becomes `[4,3,1]`.

## Interview Tips
- Mention that `priority_queue` internally uses a **binary heap**.
- Discuss when a **pair** or **struct** is needed – show custom comparator.
- Compare with **multiset** (ordered container) – heap is faster for pure top‑k operations.

## Related LeetCode Problems
- 703. Kth Largest Element in a Stream
- 215. Kth Largest Element in an Array
- 493. Reverse Pairs (using BIT, but heap can be alternative)
- 378. Kth Smallest Element in a Sorted Matrix
```
