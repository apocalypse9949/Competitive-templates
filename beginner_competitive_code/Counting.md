# Counting

## When to Use
- Problems that ask for the number of ways to arrange or select items, often under constraints (e.g., combinatorial counts, permutations, combinations).

## Recognition Patterns
- "How many strings of length N satisfy…", "Count number of subsets with sum ≤ X", "Number of ways to reach a score".

## Core Idea
Formulate the counting problem as a recurrence or closed‑form formula. Use combinatorial formulas (`nCr`, `factorial`) or DP to accumulate counts.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7; // update answer / state

// Pre‑compute factorials and inverse factorials for nCr modulo MOD
vector<long long> fact, invFact;
long long modPow(long long a, long long e) {
    long long res = 1%MOD; a %= MOD;
    while(e){ if(e&1) res = res*a%MOD; a = a*a%MOD; e >>= 1; }
    return res;
}
void initComb(int n) {
    fact.resize(n+1); invFact.resize(n+1);
    fact[0] = 1; for(int i=1;i<=n;++i) fact[i] = fact[i-1]*i%MOD; // move pointers
    invFact[n] = modPow(fact[n], MOD-2);
    for(int i=n;i>0;--i) invFact[i-1] = invFact[i]*i%MOD; // update answer
}
long long nCr(int n, int r) {
    if(r<0||r>n) return 0; // process current element
    return fact[n]*invFact[r]%MOD*invFact[n-r]%MOD; // update answer
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n; // size of problem
    initComb(n);
    // example: count ways to choose exactly k items
    int k; cin >> k;
    cout << nCr(n,k) << '\n'; // output answer
    return 0;
}
```

## Time Complexity
`O(n)` preprocessing, `O(1)` per `nCr` query.

## Space Complexity
`O(n)` for factorial tables.

## Common Variations
- Multinomial coefficients for multiple groups.
- Stars‑and‑bars for distributions.
- DP counting (e.g., coin change, partition).

## Common Mistakes
- Forgetting to take modulo after each multiplication.
- Using `int` for factorials leading to overflow.
- Not handling `k > n` cases.

## Dry Run Example
`n=5, k=2` → `5C2 = 10` (computed via pre‑computed tables).

## Interview Tips
- Mention modulo arithmetic properties (`(a+b)%MOD`, `(a*b)%MOD`).
- Explain why we compute modular inverses using Fermat's little theorem (`MOD` prime).
- Clarify when to use DP vs. combinatorial formulas.

## Similar LeetCode Problems
1. 518. Coin Change 2
2. 377. Combination Sum IV
3. 191. Number of 1 Bits (counts bits)
```
