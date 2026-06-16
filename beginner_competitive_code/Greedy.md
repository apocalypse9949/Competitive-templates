# Greedy Algorithms – Beginner Friendly

## When to Use
- The problem exhibits **optimal‑substructure** and a **greedy‑choice property** (making a locally optimal choice leads to a globally optimal solution).
- Typical scenarios: activity selection, interval scheduling, Huffman coding, minimum number of platforms, etc.

## Core Idea
Choose the best option **at each step** without reconsidering previous decisions. Prove correctness by showing that any optimal solution can be transformed to match the greedy choices.

## Classic Template (C++17) – Activity Selection (Maximum Non‑Overlapping Intervals)
```cpp
struct Interval { int start, end; };
bool cmp(const Interval& a, const Interval& b) { return a.end < b.end; }

int maxActivities(vector<Interval> a) {
    sort(a.begin(), a.end(), cmp); // sort by earliest finish time
    int count = 0;
    int lastEnd = INT_MIN;
    for (const auto& it : a) {
        if (it.start >= lastEnd) { // can attend this activity
            ++count;
            lastEnd = it.end;
        }
    }
    return count;
}
```

## Common Beginner Pitfalls
- Sorting by **start time** instead of **end time** for interval‑based problems – leads to sub‑optimal solutions.
- Forgetting to handle equal end times correctly (`<=` vs `<`).
- Assuming a greedy approach works without proving the greedy‑choice property (may produce wrong answers on deceptive inputs).

## Mini Dry‑Run Example
Intervals: `[(1,4), (3,5), (0,6), (5,7), (8,9), (5,9)]`
- Sorted by end: `[(1,4), (3,5), (0,6), (5,7), (8,9), (5,9)]`
- Pick `(1,4)`, then `(5,7)`, then `(8,9)` → total 3 activities, which is optimal.

## Interview Tips
- Start by **explaining** why a greedy choice works (optimal substructure + exchange argument).
- Show **sorting** step explicitly; many greedy problems rely on ordering.
- Compare with DP approach – if greedy works, it’s usually faster and simpler.

## Related LeetCode Problems
- 452. Minimum Number of Arrows to Burst Balloons
- 435. Non‑overlapping Intervals
- 1005. Maximize Number of Apples Collected (greedy with priority queue)
- 759. Employee Free Time
```
