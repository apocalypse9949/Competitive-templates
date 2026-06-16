# Binary Search

## When to Use
- Search for an element or boundary condition in a **monotonic** (sorted) array or answer space.
- Problems that ask for the *minimum* / *maximum* feasible value.

## Recognition Patterns
- "Find the smallest/largest X such that ...", "Search in a rotated sorted array", "Find peak element".

## Core Idea
Iteratively shrink the search interval `[low, high]` using the middle element to decide which half may contain the answer.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

// Return true if condition holds for `mid`
bool ok(long long mid, const vector<int>& a) {
    // placeholder: implement problem‑specific check
    return false;
}

long long binarySearch(const vector<int>& a, long long lo, long long hi) {
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2; // avoid overflow
        if (ok(mid, a)) {
            hi = mid; // update answer / state, move pointers left
        } else {
            lo = mid + 1; // move pointers right
        }
    }
    return lo; // lo == hi -> answer
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n; vector<int>a(n); for(int &x:a)cin>>x; // sorted if required
    long long ans = binarySearch(a, 0, 1e9); // adjust bounds
    cout << ans << '\n';
    return 0;
}
```

## Time Complexity
`O(log(range) * check)` – typically `O(log n)` when the check is `O(1)`.

## Space Complexity
`O(1)` auxiliary.

## Common Variations
- Binary search on answer (parametric search).
- Lower/upper bound (`std::lower_bound`, `std::upper_bound`).
- Search in rotated array, in matrix, in function monotonicity.

## Common Mistakes
- Infinite loop by not moving `lo`/`hi` correctly.
- Off‑by‑one: using `mid = (lo+hi)/2` may cause overflow.
- Forgetting to handle duplicate values for lower/upper bound.

## Dry Run Example
Find smallest `x` such that `x*x >= 20`:
- lo=0, hi=20, mid=10 → ok? 100>=20 true → hi=10
- lo=0, hi=10, mid=5 → ok? 25>=20 true → hi=5
- lo=0, hi=5, mid=2 → ok? 4>=20 false → lo=3
- lo=3, hi=5, mid=4 → ok? 16>=20 false → lo=5
- lo==hi==5 → answer 5.

## Interview Tips
- State the invariant: `[lo, hi)` or `[lo, hi]`.
- Mention using `while(lo < hi)` for left‑biased search.
- Discuss when to use `double` binary search for real values.

## Similar LeetCode Problems
1. 704. Binary Search
2. 162. Find Peak Element
3. 410. Split Array Largest Sum (binary search on answer)
```
