# Hash Table

## When to Use
- Need O(1) average‑time look‑ups, insertions or deletions for key‑value associations.
- Problems involving frequency counting, mapping indices, or detecting duplicates.

## Recognition Patterns
- "Find the first/last element that appears..."
- "Count occurrences of each number/character".
- "Two‑sum / three‑sum" style problems.

## Core Idea
Use an `unordered_map` (or `unordered_set`) to store the needed association while iterating once over the data.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

// Example: counting frequencies
vector<int> solve(const vector<int>& nums) {
    unordered_map<int,int> freq; // key -> count
    for (int x : nums) {
        // update answer / auxiliary state
        ++freq[x]; // process current element
    }
    // Example: collect keys appearing more than once
    vector<int> duplicates;
    for (auto &p : freq) {
        if (p.second > 1) duplicates.push_back(p.first); // update answer
    }
    return duplicates;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n; vector<int>a(n); for(int &x:a)cin>>x;
    auto ans = solve(a);
    for(int v:ans) cout<<v<<' '; cout<<"\n";
    return 0;
}
```

## Time Complexity
`O(n)` – each element is processed once; unordered‑map operations are O(1) average.

## Space Complexity
`O(n)` in the worst case for the map storage.

## Common Variations
- Mapping value → index (store first/last occurrence).
- Using `unordered_set` for existence checks.
- Storing vectors of indices for each key.

## Common Mistakes
- Forgetting to reserve bucket count (`map.reserve(n)`) which may cause re‑hashing slowdown.
- Collisions leading to worst‑case O(n) per operation (rare in interview).
- Mixing signed/unsigned keys causing accidental negative indexing.

## Dry Run Example
Input: `[2,5,1,2,3,5]`
- After loop, `freq` = {2:2,5:2,1:1,3:1}
- Duplicates collected → `[2,5]`.

## Interview Tips
- Mention that `unordered_map` is average‑case O(1) but `map` (red‑black tree) gives O(log n) guarantee.
- Discuss custom hash for pair<int,int> when needed.
- Highlight the importance of clearing the map between test cases.

## Similar LeetCode Problems
1. 1. Two Sum
2. 347. Top K Frequent Elements
3. 219. Contains Duplicate II
```
