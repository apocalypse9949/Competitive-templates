# Queue

## When to Use
- Problems that need FIFO order processing, level‑order traversal, or managing tasks/events in the order they arrive.

## Recognition Patterns
- "Print level order of a binary tree", "Implement a circular queue", "Simulate a printer queue".

## Core Idea
Use `std::queue<T>` (or `deque<T>` for more operations). Push elements at the back, pop from the front, and optionally inspect the front element.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n; // number of operations
    queue<int> q; // update answer / state
    while(n--){
        string cmd; cin >> cmd; // process current element
        if(cmd == "push"){ int x; cin >> x; q.push(x); } // move pointers
        else if(cmd == "pop"){ if(!q.empty()) q.pop(); }
        else if(cmd == "front"){ if(!q.empty()) cout << q.front() << '\n'; else cout << "EMPTY\n"; }
        else if(cmd == "size"){ cout << q.size() << '\n'; }
    }
    return 0;
}
```

## Time Complexity
`O(1)` amortized per operation.

## Space Complexity
`O(k)` where *k* is the maximum size of the queue.

## Common Variations
- Use `deque` for double‑ended queue operations.
- Implement circular buffer manually for O(1) memory.
- BFS queue for graph traversal.

## Common Mistakes
- Forgetting to check `empty()` before accessing `front()` or `pop()`.
- Mixing up push/pop order leading to reversed output.

## Dry Run Example
Operations: `push 1`, `push 2`, `front` → prints `1`, `pop`, `front` → prints `2`.

## Interview Tips
- Mention that `std::queue` is a wrapper around `deque` and provides only push/pop/front/empty/size.
- Explain when a `deque` is preferable (need to pop from both ends).
- For large data, discuss using a circular array to avoid dynamic allocation.

## Similar LeetCode Problems
1. 102. Binary Tree Level Order Traversal
2. 933. Number of Recent Calls (queue of timestamps)
3. 225. Implement Stack using Queues (inverse use case)
```
