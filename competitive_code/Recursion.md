# Recursion

## When to Use
- Problems that can be expressed as solving a smaller sub‑problem of the same type (e.g., tree traversals, backtracking, divide‑and‑conquer, DP with memoization).

## Recognition Patterns
- "Calculate the n‑th Fibonacci", "Traverse a binary tree", "Generate all permutations", "Solve the Tower of Hanoi".

## Core Idea
Define a function that calls itself with a reduced argument until a base case is reached. Preserve state via parameters or global/static structures.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

// Example: n‑th Fibonacci with memoization (top‑down DP)
vector<long long> memo;
long long fib(int n){
    // base case – update answer
    if(n <= 1) return n; // process current element
    if(memo[n] != -1) return memo[n]; // move pointers (cached)
    return memo[n] = fib(n-1) + fib(n-2); // update answer / state
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    memo.assign(n+1, -1); // update answer / state
    cout << fib(n) << '\n'; // output answer
    return 0;
}
```

## Time Complexity
`O(N)` for the memoized version (each state computed once). Pure recursion without memo may be exponential.

## Space Complexity
`O(N)` recursion stack + memo table.

## Common Variations
- Pure recursion without memo (exponential).
- Tail‑recursion (can be optimized by compiler).
- Recursion on trees/graphs (DFS).

## Common Mistakes
- Missing base case → infinite recursion / stack overflow.
- Not memoizing when needed → TLE.
- Using global variables that persist across test cases.

## Dry Run Example
`fib(5)` → calls `fib(4)` & `fib(3)` … memo stores results, final answer `5`.

## Interview Tips
- Mention that recursion depth must fit the call stack; for deep recursion convert to iterative.
- Explain when to prefer memoization to avoid repeated work.
- State space‑time trade‑off of storing the memo table.

## Similar LeetCode Problems
1. 509. Fibonacci Number
2. 96. Unique Binary Search Trees
3. 131. Palindrome Partitioning
```
