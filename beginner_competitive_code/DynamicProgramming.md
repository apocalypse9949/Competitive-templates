# Dynamic Programming – Beginner Friendly

## When to Use
- Problems that can be broken down into **overlapping sub‑problems** with optimal sub‑structure.
- You need to compute a result for many states efficiently by **reusing** previously computed results.

## Core Idea
Define a **state** (usually an index or a pair of indices) representing a sub‑problem, then write a **recurrence** that expresses this state in terms of smaller states. Store the results in a table (memoization) to avoid recomputation.

## Classic Template: 0/1 Knapsack (Iterative DP)
```cpp
int n = items.size();
int W = capacity;
vector<int> dp(W + 1, 0);
for (int i = 0; i < n; ++i) {
    for (int w = W; w >= items[i].weight; --w) {
        dp[w] = max(dp[w], dp[w - items[i].weight] + items[i].value);
    }
}
int answer = dp[W];
```
*We iterate `w` backwards to avoid using the same item more than once.*

## Recursive Memoization (Top‑Down) Example – Fibonacci
```cpp
vector<long long> memo(100, -1);
long long fib(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fib(n-1) + fib(n-2);
}
```

## Common Beginner Pitfalls
- **Incorrect state definition** – make sure the state captures everything needed to make a decision.
- Forgetting to **initialize** DP table (e.g., using `-INF` for maximization problems).
- Not handling **base cases** correctly, leading to out‑of‑bounds access.
- Using **forward loops** when you need a *0/1* knapsack (can cause reuse of an item).

## Mini Dry‑Run (Fibonacci up to 5)
`memo` initially `[-1,...]`. Calls: `fib(5)` → `fib(4)+fib(3)` → … stores results as they return. Final table: `[0,1,1,2,3,5]`.

## Interview Tips
- Mention **time‑space trade‑off** – sometimes you can roll the DP array to O(1) space.
- State whether you use **bottom‑up** (iterative) or **top‑down** (memoization) and why.
- Explain how to reconstruct the solution (e.g., path reconstruction for knapsack).

## Related LeetCode Problems
- 70. Climbing Stairs (simple DP)
- 198. House Robber
- 322. Coin Change
- 518. Coin Change 2
```
