# Counting Sort

## When to Use
- Problems that require sorting integers with a known limited range in linear time (e.g., sorting ages, scores, or IDs).

## Recognition Patterns
- "Sort an array where elements are between 0 and K", "Frequency counting", "Stable sorting of small‑range integers".

## Core Idea
Count the occurrences of each value, compute prefix sums to know the final positions, and place elements into an output array preserving stability.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> countingSort(const vector<int>& a, int maxVal) {
    int n = a.size();
    vector<int> cnt(maxVal + 1, 0); // update answer / state
    for (int x : a) cnt[x]++; // process current element
    // prefix sums to get positions
    for (int i = 1; i <= maxVal; ++i) cnt[i] += cnt[i-1]; // move pointers
    vector<int> out(n);
    for (int i = n - 1; i >= 0; --i) { // stable, iterate backwards
        out[--cnt[a[i]]] = a[i]; // update answer
    }
    return out;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, maxVal; cin >> n >> maxVal;
    vector<int> a(n);
    for(int &x:a) cin >> x;
    auto sorted = countingSort(a, maxVal);
    for(int v:sorted) cout << v << ' ';
    cout << '\n';
    return 0;
}
```

## Time Complexity
`O(N + K)` where `K = maxVal`.

## Space Complexity
`O(N + K)` for count array and output.

## Common Variations
- Radix sort uses counting sort as a sub‑routine for each digit.
- Sorting negative numbers by offsetting values.

## Common Mistakes
- Forgetting to allocate `cnt` of size `maxVal+1`.
- Not handling values outside `[0, maxVal]` (out‑of‑range error).
- Losing stability if you iterate forward when placing elements.

## Dry Run Example
`a = [4,2,2,8,3,3,1], maxVal=8` → after counting sort: `[1,2,2,3,3,4,8]`.

## Interview Tips
- Emphasize that counting sort is stable and works when the range is comparable to `N`.
- Mention memory trade‑off for large ranges.
- If asked for "linear time", verify constraints permit counting sort.

## Similar LeetCode Problems
1. 164. Maximum Gap (uses counting sort idea)
2. 1002. Find Common Characters (frequency counting)
3. 912. Sort an Array (alternative linear sort for limited range)
```
