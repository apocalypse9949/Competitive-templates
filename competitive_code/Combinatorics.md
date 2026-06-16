# Combinatorics

## When to Use
- Problems that ask for the number of ways to arrange, select, or partition objects under constraints (e.g., counting permutations, combinations, partitions).

## Recognition Patterns
- "How many ways to choose k items from n", "Count distinct strings of length L", "Number of ways to distribute identical balls into boxes".

## Core Idea
Use factorials and modular inverses for `nCr`, apply stars‑and‑bars for distributions, or use DP for constrained counts. Pre‑compute factorials up to needed `N` for O(1) queries.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
vector<long long> fact, invFact;
long long modPow(long long a, long long e){
    long long r = 1%MOD; a %= MOD;
    while(e){ if(e&1) r = r*a%MOD; a = a*a%MOD; e >>= 1; }
    return r;
}
void initComb(int N){
    fact.resize(N+1); invFact.resize(N+1);
    fact[0]=1; for(int i=1;i<=N;++i) fact[i]=fact[i-1]*i%MOD; // update answer
    invFact[N]=modPow(fact[N], MOD-2);
    for(int i=N;i>0;--i) invFact[i-1]=invFact[i]*i%MOD; // move pointers
}
long long nCr(int n,int r){
    if(r<0||r>n) return 0; // process current element
    return fact[n]*invFact[r]%MOD*invFact[n-r]%MOD; // update answer
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin>>N; // max needed n
    initComb(N);
    int q; cin>>q;
    while(q--){
        int n,k; cin>>n>>k; // query
        cout << nCr(n,k) << '\n'; // output answer
    }
    return 0;
}
```

## Time Complexity
`O(N)` preprocessing, `O(1)` per query.

## Space Complexity
`O(N)` for factorial tables.

## Common Variations
- Multinomial coefficient for multiple groups.
- Stars‑and‑bars for distributing identical items.
- DP counting (coin change, partition) when modulus not prime.

## Common Mistakes
- Using `int` for factorials causing overflow before modulo.
- Forgetting to handle `k>n`.
- Not taking modulo after each multiplication.

## Dry Run Example
`N=10, query (5,2)` → `5C2 = 10`.

## Interview Tips
- Explain why Fermat's little theorem works for modular inverse when `MOD` is prime.
- Mention alternative Lucas theorem for large `n` with small `MOD`.
- Clarify when to use DP vs. combinatorial formula.

## Similar LeetCode Problems
1. 518. Coin Change 2
2. 377. Combination Sum IV
3. 191. Number of 1 Bits (counts bits – combinatorial flavour)
```
