# Backtracking

## When to Use
- Problems that require exploring all possibilities, often with constraints that prune the search space (e.g., puzzles, combinatorial generation, subset enumeration).

## Recognition Patterns
- "Generate all permutations", "Solve Sudoku", "Word break", "N‑Queens".

## Core Idea
Recursively build a partial solution, make a choice, recurse, then backtrack (undo the choice). Use a `vector`/`string` to hold current state and a `bool`/`unordered_set` to mark used elements.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int>& path, vector<int>& nums, vector<bool>& used, vector<vector<int>>& res) {
    // base case – update answer
    if (path.size() == nums.size()) {
        res.push_back(path);
        return;
    }
    // iterate over candidates
    for (int i = 0; i < (int)nums.size(); ++i) {
        if (used[i]) continue; // skip already used
        // process current element
        used[i] = true; // move pointers (choose)
        path.push_back(nums[i]); // update state
        backtrack(path, nums, used, res); // recurse deeper
        // undo choice (backtrack)
        path.pop_back(); // move pointers back
        used[i] = false; // update answer / state
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums = {1,2,3}; // example input
    vector<bool> used(nums.size(), false);
    vector<int> path;
    vector<vector<int>> res;
    backtrack(path, nums, used, res);
    // output all permutations
    for (auto &p : res) {
        for (int x : p) cout << x << ' '; cout << '\n';
    }
    return 0;
}
```

## Time Complexity
`O(k * n!)` for generating all permutations of `n` items (k = cost per leaf). Generally exponential.

## Space Complexity
`O(n)` recursion stack plus storage for current path.

## Common Variations
- Subset generation (choose or skip each element).
- Permutations with duplicates (skip identical numbers).
- Constraint‑driven pruning (e.g., early stop when sum exceeds target).

## Common Mistakes
- Forgetting to undo changes (backtrack) leading to corrupted state.
- Not handling duplicates correctly → duplicate results.
- Exceeding recursion depth for large `n` (use iterative stack).

## Dry Run Example
Generating permutations of `[1,2]`:
- choose 1 → path `[1]` → recurse, choose 2 → output `[1,2]` → backtrack, choose 2 first → output `[2,1]`.

## Interview Tips
- Mention pruning strategies early to cut exponential blow‑up.
- State the trade‑off between recursion and explicit stack for deep recursion.
- Clarify expected output size; if too large, discuss limiting with early exit.

## Similar LeetCode Problems
1. 46. Permutations
2. 51. N‑Queens
3. 39. Combination Sum
```
