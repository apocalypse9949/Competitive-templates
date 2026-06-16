# Binary Search – Beginner Friendly

## When to Use
- The input array is **sorted** (ascending or descending).
- You need to find an element, the first/last occurrence, or the **boundary** where a predicate changes.

## Core Idea
Repeatedly halve the search interval while keeping the invariant that the answer lies inside the interval.

## Classic Template (C++17)
```cpp
int binarySearch(const vector<int>& arr, int target) {
    int lo = 0, hi = (int)arr.size() - 1; // inclusive bounds
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2; // avoid overflow
        if (arr[mid] == target) return mid;   // found
        if (arr[mid] < target) lo = mid + 1; // search right half
        else hi = mid - 1;                    // search left half
    }
    return -1; // not found
}
```

## Finding First / Last Position (Lower / Upper Bound)
```cpp
// first index where arr[idx] >= target
int lowerBound(const vector<int>& arr, int target) {
    int lo = 0, hi = (int)arr.size(); // hi is exclusive
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo; // may be arr.size() if target > all elements
}

// first index where arr[idx] > target (upper bound)
int upperBound(const vector<int>& arr, int target) {
    int lo = 0, hi = (int)arr.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] <= target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}
```

## Common Pitfalls for Beginners
- **Off‑by‑one**: mixing inclusive/exclusive bounds. Use one style consistently.
- Forget to update `mid` calculation to avoid overflow (`lo + (hi-lo)/2`).
- Not handling the case when the target does not exist – return `-1` or `arr.size()` accordingly.

## Mini Dry‑Run Example
Array: `[1,3,5,7,9]`, target `5` → `mid=2`, returns index `2`.
Target `6` → `lowerBound` returns `3` (first >=6), `upperBound` returns `3` (first >6).

## Interview Tips
- Mention that binary search works on **monotonic** predicates, not just plain equality.
- Show how to adapt the template for "search the answer" problems (e.g., maximum feasible value).
- Compare with linear scan – O(log N) vs O(N).

## Related LeetCode Problems
- 704. Binary Search
- 34. Find First and Last Position of Element in Sorted Array
- 69. Sqrt(x) (binary search on answer)
- 162. Find Peak Element (binary search on condition)
```
