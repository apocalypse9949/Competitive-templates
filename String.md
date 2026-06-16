# String

## When to Use
- Problems that involve manipulation, pattern matching, or analysis of a sequence of characters.

## Recognition Patterns
- "Given a string s, find..."
- "Check if a string is a palindrome", "Longest Substring without Repeating Characters", etc.

## Core Idea
Traverse the string while maintaining pointers or counters; often combine with sliding‑window, hash maps, or two‑pointer techniques.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

// Template for typical string problems
int solve(const string& s) {
    int n = s.size();
    // Example: longest substring without repeating characters
    vector<int> last(256, -1); // last index of each character
    int start = 0, best = 0;
    for (int i = 0; i < n; ++i) {
        // update start to avoid duplicates
        start = max(start, last[(unsigned char)s[i] + 1]);
        // calculate current window length
        best = max(best, i - start + 1);
        // store last occurrence
        last[(unsigned char)s[i]] = i;
    }
    return best; // placeholder result
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    cout << solve(s) << '\n';
    return 0;
}
```

## Time Complexity
`O(n)` – single pass over the string.

## Space Complexity
`O(1)` extra (256‑size array) or `O(k)` where k is alphabet size.

## Common Variations
- Two‑pointer sliding window
- Prefix function / KMP for pattern matching
- String building with `stringstream` or `push_back`

## Common Mistakes
- Forgetting to handle `unsigned char` cast causing negative indices.
- Ignoring Unicode/multibyte characters.
- Not resetting state when moving the left pointer.

## Dry Run Example
Input: `"abca"`
- i=0: start=0, best=1, last['a']=0
- i=1: start=0, best=2, last['b']=1
- i=2: start=0, best=3, last['c']=2
- i=3: start=max(0, last['a']+1=1)=1, best=3, last['a']=3
Result = 3 ("abc").

## Interview Tips
- Clarify case‑sensitivity and allowed character set.
- Mention using `unordered_map<char,int>` when alphabet is large.
- Discuss converting to numeric indices for speed.

## Similar LeetCode Problems
1. 3. Longest Substring Without Repeating Characters
2. 5. Longest Palindromic Substring
3. 14. Longest Common Prefix
```
