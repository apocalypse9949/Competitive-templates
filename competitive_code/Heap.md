# Heap (Priority Queue)

## When to Use
- Need to repeatedly access the minimum or maximum element efficiently.
- Problems involving k‑largest/k‑smallest, merging streams, or scheduling with earliest deadline.

## Recognition Patterns
- "Find the k‑th largest element", "Merge n sorted lists", "Running median", "Dijkstra" (min‑heap).

## Core Idea
Use `std::priority_queue` (max‑heap by default) or customize with `greater<>` for min‑heap. Push elements, pop when needed.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

// Example: k‑largest elements using min‑heap of size k
vector<int> kLargest(const vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap; // update answer / state
    for (int x : nums) {
        if ((int)minHeap.size() < k) {
            minHeap.push(x); // process current element
        } else if (x > minHeap.top()) {
            minHeap.pop(); // move pointers (remove smallest)
            minHeap.push(x); // update answer
        }
    }
    vector<int> res;
    while (!minHeap.empty()) { res.push_back(minHeap.top()); minHeap.pop(); } // extract
    sort(res.rbegin(), res.rend()); // optional order
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k; cin>>n>>k; vector<int>a(n); for(int &x:a)cin>>x;
    auto ans = kLargest(a,k);
    for(int v:ans) cout<<v<<' '; cout<<"\n";
    return 0;
}
```

## Time Complexity
`O(n log k)` for maintaining a heap of size *k*.

## Space Complexity
`O(k)` auxiliary.

## Common Variations
- Max‑heap for k‑smallest.
- Using heap for Dijkstra (pair<dist,node>).
- Merging multiple sorted arrays.

## Common Mistakes
- Forgetting to specify `greater<>` for a min‑heap.
- Pushing all elements then extracting (O(n log n) instead of O(n log k)).
- Not handling `k` larger than `n`.

## Dry Run Example
`nums=[5,1,3,6,4], k=3` → heap evolves to `[5,4,6]` → result `[6,5,4]`.

## Interview Tips
- Mention that `priority_queue` operations are `O(log size)`.
- Clarify whether ties matter; use `pair<value,index>` if stable ordering needed.
- For sliding‑window median, use two heaps.

## Similar LeetCode Problems
1. 215. Kth Largest Element in an Array
2. 703. Kth Largest Element in a Stream
3. 973. K Closest Points to Origin
```
