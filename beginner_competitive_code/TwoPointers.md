# Two Pointers – Beginner Friendly

## When to Use
- The array (or string) is **sorted** or you need to find pairs/triplets that satisfy a condition.
- Problems that require a **linear scan** from both ends (e.g., removing duplicates, partitioning).

## Core Idea
Maintain two indices (`left` and `right`) that move towards each other (or one moves forward while the other lags). Adjust pointers based on the predicate until the condition is met.

## Classic Template: 2‑Sum in Sorted Array
```cpp
vector<int> twoSumSorted(const vector<int>& arr, int target) {
    int left = 0, right = (int)arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) return {left, right};
        if (sum < target) ++left;   // need larger sum
        else --right;                // need smaller sum
    }
    return {}; // not found
}
```

## Sliding Window vs Two Pointers
- **Two pointers** often work on **sorted** data (or when the window size is flexible).
- **Sliding window** keeps a contiguous block of elements; two pointers may also be used for variable‑size windows (see Sliding Window template).

## Common Pitfalls for Beginners
- Forgetting to **increment/decrement** pointers inside the loop, causing infinite loops.
- Not handling **duplicate values** correctly – may need to skip equal elements after finding a match.
- Assuming the input is sorted; if not, sort first (which changes indices).

## Mini Dry‑Run Example (Find pair sum 9 in `[1,2,3,4,5,6]`)
- left=0 (1), right=5 (6) → sum=7 <9 → left++
- left=1 (2), right=5 (6) → sum=8 <9 → left++
- left=2 (3), right=5 (6) → sum=9 → return indices (2,5).

## Interview Tips
- Mention that the technique runs in **O(N)** after sorting (O(N log N) total).
- Explain why it works: the sum is monotonic when moving pointers outward/inward on a sorted array.
- Compare with hash‑map approach (O(N) time, O(N) space) – two‑pointer uses O(1) extra space.

## Related LeetCode Problems
- 167. Two Sum II – Input array is sorted
- 15. 3Sum (extend two‑pointer inside a loop)
- 11. Container With Most Water
- 345. Reverse Vowels of a String (two‑pointer on string)
```
