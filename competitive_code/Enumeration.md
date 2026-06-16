# Enumeration

## When to Use
- Problems that require generating all possibilities of a set (e.g., subsets, permutations, combinations) often with constraints to prune the search space.

## Recognition Patterns
- "Generate all subsets of a set", "List all k‑combinations", "Enumerate all bit masks of length n".

## Core Idea
Use a loop over integers from `0` to `(1<<n)-1` for bit‑mask enumeration, or recursive backtracking for variable‑size combinations. Maintain a container for the current choice and output when a terminal condition is met.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

// Example: enumerate all subsets of a vector<int> using bitmask
void enumerateSubsets(const vector<int>& a) {
    int n = a.size(); // update answer / state
    for (int mask = 0; mask < (1<<n); ++mask) { // process current element
        vector<int> subset;
        for (int i = 0; i < n; ++i) {
            if (mask & (1<<i)) subset.push_back(a[i]); // move pointers (select)
        }
        // output current subset
        cout << "{ ";
        for (int x : subset) cout << x << ' ';
        cout << "}\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n; vector<int>a(n);
    for(int &x:a)cin>>x;
    enumerateSubsets(a);
    return 0;
}
```

## Time Complexity
`O( n * 2^n )` – each of the `2^n` subsets may copy up to `n` elements.

## Space Complexity
`O(n)` for the temporary subset vector (output not counted).

## Common Variations
- Enumerate permutations with `next_permutation` or recursion.
- Generate combinations of size `k` using recursion or iterative combinatorial logic.
- Lexicographic enumeration of binary strings.

## Common Mistakes
- Forgetting to reset the temporary container for each iteration.
- Using signed shift on large `n` (overflow), guard with `1LL<<n` for `n>30`.
- Not handling empty set correctly (mask = 0).

## Dry Run Example
`a = [1,2,3]` → masks `0..7` produce `{}`, `{1}`, `{2}`, `{1,2}`, `{3}`, `{1,3}`, `{2,3}`, `{1,2,3}`.

## Interview Tips
- Mention that bitmask enumeration is O(2^n) and only feasible for `n <= 20` roughly.
- For combinatorial generation, discuss pruning early when constraints are violated.
- Use `std::next_permutation` for lexicographic order when needed.

## Similar LeetCode Problems
1. 78. Subsets
2. 46. Permutations
3. 77. Combinations
```
