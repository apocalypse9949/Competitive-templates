# Math

## When to Use
- Problems that require arithmetic operations, number theory, combinatorics, or modular calculations.

## Recognition Patterns
- "Find the nth Fibonacci number modulo 1e9+7"
- "Count ways to arrange objects" (combinatorial formulas)
- "Check for prime, GCD, LCM"

## Core Idea
Utilize fast exponentiation, modular arithmetic, Euclidean algorithm, and combinatorial pre‑computations.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;

// fast exponentiation (a^b % MOD)
long long modPow(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// modular inverse using Fermat (MOD must be prime)
long long modInv(long long a) { return modPow(a, MOD-2); }

// nCr using factorials
vector<long long> fact, invFact;
void initFact(int n) {
    fact.resize(n+1); invFact.resize(n+1);
    fact[0] = 1;
    for (int i=1;i<=n;++i) fact[i] = fact[i-1]*i % MOD;
    invFact[n] = modInv(fact[n]);
    for (int i=n;i>0;--i) invFact[i-1] = invFact[i]*i % MOD;
}
long long nCr(int n, int r) {
    if (r<0||r>n) return 0;
    return fact[n]*invFact[r]%MOD*invFact[n-r]%MOD;
}

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    // Example: compute C(10,3)
    initFact(1000);
    cout << nCr(10,3) << '\n';
    return 0;}
```

## Time Complexity
- `O(log b)` for `modPow`.
- `O(1)` per query after `O(n)` preprocessing for factorials.

## Space Complexity
- `O(n)` for factorial tables.

## Common Variations
- Chinese Remainder Theorem, Lucas theorem for large n.
- Using `__int128` for intermediate multiplication to avoid overflow.

## Common Mistakes
- Forgetting to take modulo after each multiplication.
- Using `int` where `long long` is needed for intermediate results.

## Dry Run Example
Compute `C(5,2)` with MOD 1e9+7 → 10.

## Interview Tips
- Mention handling of large n with pre‑computation.
- Discuss modular inverse when MOD is prime vs non‑prime.
- Know Euclidean algorithm for GCD.

## Similar LeetCode Problems
- 53. Maximum Subarray (Kadane’s algorithm – math on arrays)
- 632. Smallest Range Covering Elements from K Lists (use min‑heap + math)
- 264. Ugly Number II (uses prime factor enumeration)
