# Greedy

## When to Use
- When a locally optimal choice leads to a globally optimal solution. Typical in scheduling, selection, and optimization problems.

## Recognition Patterns
- "Select the maximum number of tasks", "Minimum number of intervals to remove", "Maximum profit with constraints".

## Core Idea
Sort or prioritize elements by a key (e.g., end time, value/weight) and iteratively pick the best candidate that does not violate constraints.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

// Example: activity selection – maximum number of non‑overlapping intervals
int greedyActivitySelection(vector<pair<int,int>>& intervals) {
    // sort by finishing time
    sort(intervals.begin(), intervals.end(),
         [](const auto& a, const auto& b){ return a.second < b.second; }); // update answer / state
    int cnt = 0;
    int lastEnd = INT_MIN; // move pointers
    for (auto &it : intervals) {
        if (it.first >= lastEnd) { // process current element
            ++cnt; // update answer
            lastEnd = it.second; // move pointer to new end
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<int,int>> seg(n);
    for (auto &p : seg) cin >> p.first >> p.second;
    cout << greedyActivitySelection(seg) << '\n';
    return 0;
}
```

## Time Complexity
`O(n log n)` for sorting, then `O(n)` scan.

## Space Complexity
`O(1)` extra (apart from input storage).

## Common Variations
- Fractional knapsack (sort by value/weight).
- Minimum number of platforms, meeting rooms.
- Greedy coloring, Huffman coding (uses priority queue).

## Common Mistakes
- Assuming greedy works without proof; verify exchange argument.
- Incorrect sort key leading to sub‑optimal selection.
- Forgetting to handle equal keys consistently.

## Dry Run Example
Intervals: `[(1,3),(2,5),(4,7)]`
- Sorted by end → `[(1,3),(2,5),(4,7)]`
- Pick (1,3), lastEnd=3, cnt=1
- (2,5) start<3 → skip
- (4,7) start>=3 → pick, cnt=2.

## Interview Tips
- Explain why the greedy choice is optimal (exchange argument or proof sketch).
- Mention edge cases: zero‑length intervals, identical start/end.
- Discuss when to use a priority queue for dynamic greedy.

## Similar LeetCode Problems
1. 455. Assign Cookies
2. 122. Best Time to Buy and Sell Stock II
3. 452. Minimum Number of Arrows to Burst Balloons
```
