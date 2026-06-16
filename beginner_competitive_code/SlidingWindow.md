# Sliding Window – Beginner Friendly

## When to Use
- Problems that require **finding a sub‑array / sub‑string** satisfying a condition (sum, length, distinct characters, etc.) in **O(N)** time.
- The window can be **fixed size** (e.g., moving average) or **dynamic** (expand/shrink based on a predicate).

## Core Idea
Maintain two pointers `left` and `right` that delimit the current window. Expand `right` to include new elements, and shrink `left` while the window violates the condition.

## Fixed‑Size Window Template (C++17)
```cpp
vector<int> nums = {/*...*/};
int k = 3; // window size
int sum = 0;
for (int i = 0; i < k; ++i) sum += nums[i]; // initial window
for (int i = k; i < nums.size(); ++i) {
    sum += nums[i] - nums[i - k]; // slide window by 1
    // process sum here
}
```

## Dynamic Window Template (e.g., longest sub‑array with sum ≤ S)
```cpp
int target = 15; // example constraint
int left = 0, cur = 0, best = 0;
for (int right = 0; right < nums.size(); ++right) {
    cur += nums[right];
    while (cur > target && left <= right) {
        cur -= nums[left++]; // shrink from left
    }
    best = max(best, right - left + 1); // length of valid window
}
```

## Common Pitfalls for Beginners
- Forgetting to **remove** the leftmost element when shrinking the window (leads to incorrect sums). 
- Using `>=` vs `>` in the while‑condition – off‑by‑one errors on boundary conditions. 
- Assuming the window size is always increasing – for some problems you need to **reset** the window entirely.

## Mini Dry‑Run Example (max sub‑array sum ≤ 7)
Array `[2,1,5,1,3,2]`
- Extend right: sum=2 → ok, best=1
- Add 1: sum=3 → ok, best=2
- Add 5: sum=8 >7 → shrink left (remove 2) → sum=6, left=1 → window `[1,5]`
- Continue… eventually best length = 3 (`[1,5,1]` after adjustments).

## Interview Tips
- State the **O(N)** guarantee: each element is added and removed at most once.
- Mention variants: **minimum size sub‑array with sum ≥ S**, **longest substring with at most K distinct chars**, etc.
- Compare with brute‑force O(N²) – explain why sliding window is optimal for monotonic constraints.

## Related LeetCode Problems
- 209. Minimum Size Subarray Sum
- 3. Longest Substring Without Repeating Characters
- 239. Sliding Window Maximum
- 567. Permutation in String
```
