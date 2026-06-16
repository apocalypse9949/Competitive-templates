# Simulation

## When to Use
- Problems where the process can be directly emulated step‑by‑step (e.g., game simulations, process scheduling, physics steps) and constraints allow O(N) or O(T) operations.

## Recognition Patterns
- "Simulate the movement of robots", "Process events in chronological order", "Calculate final state after K operations".

## Core Idea
Iterate through time or events, updating the system state according to the rules. Use appropriate data structures (queues, priority queues) to manage upcoming events.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Event {
    long long time; // when the event occurs
    // other fields…
    bool operator<(const Event& other) const { return time > other.time; } // min‑heap
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n; // number of initial entities
    priority_queue<Event> pq; // process current element / move pointers
    for(int i=0;i<n;++i){
        long long t; cin>>t; // placeholder
        pq.push({t}); // update answer / state
    }
    while(!pq.empty()){
        Event cur = pq.top(); pq.pop(); // move pointers
        // process cur event – update state
        // possibly generate new events and push them
    }
    // final answer
    cout << "simulation done" << '\n';
    return 0;
}
```

## Time Complexity
`O(E log E)` where `E` is the number of processed events (each push/pop is log E).

## Space Complexity
`O(E)` for the event queue.

## Common Variations
- Fixed‑step simulation (for loop over time steps).
- Event‑driven simulation using a min‑heap.
- Cellular‑automaton style updates on a grid.

## Common Mistakes
- Forgetting to handle simultaneous events (same timestamp) correctly.
- Infinite loops when events generate themselves without progress.
- Using `int` for time when values exceed 2³¹‑1.

## Dry Run Example
Simulate a queue where each person takes 2 seconds, arrivals at times `[0,1,3]`. The heap processes arrivals and service completions, yielding total finish time 7.

## Interview Tips
- Clarify constraints: if `T` (total time) is ≤ 10⁶, a simple loop may be fine; otherwise use event‑driven.
- Discuss time‑step size (discrete vs continuous).
- Mention that floating‑point errors can appear in physics simulations – use integers if possible.

## Similar LeetCode Problems
1. 207. Course Schedule (topological sort can be seen as simulation of prerequisites)
2. 453. Minimum Moves to Equal Array Elements (simulate moves)
3. 1796. Check if Sentence Is Pangram (simple simulation of letter presence)
```
