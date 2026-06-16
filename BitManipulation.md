# Bit Manipulation

## When to Use
- Problems that involve integer representation, masks, parity, set operations, or need O(1) state updates.
- Typical in combinatorial enumeration, optimization of space, cryptography‑style puzzles, and low‑level algorithmic tricks.

## Recognition Patterns
- "Find the number of set bits",
- "Check if a number is a power of two",
- "Swap odd and even bits",
- "Find missing number using XOR",
- "Maximum XOR of two numbers",
- "Count subarrays with a given OR/AND",
- "Generate all subsets via bitmask".

## Core Idea
Leverage the binary representation of integers. Use bitwise operators (`&`, `|`, `^`, `~`, `<<`, `>>`) to query, set, toggle, or combine bits in constant time.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ----------- Helper Functions -----------

// Count set bits (popcount) – works for 32/64‑bit numbers
inline int popcnt(unsigned int x) { return __builtin_popcount(x); }
inline int popcntll(unsigned long long x) { return __builtin_popcountll(x); }

// Check if x is power of two (x > 0 && (x & (x-1)) == 0)
inline bool isPowerOfTwo(ll x) { return x > 0 && (x & (x-1)) == 0; }

// Isolate lowest set bit: x & -x
inline ll lowBit(ll x) { return x & -x; }

// Turn off the lowest set bit: x & (x-1)
inline ll turnOffLowBit(ll x) { return x & (x-1); }

// Get i‑th bit (0‑based)
inline bool getBit(ll x, int i) { return (x >> i) & 1LL; }

// Set i‑th bit to 1
inline ll setBit(ll x, int i) { return x | (1LL << i); }

// Clear i‑th bit to 0
inline ll clearBit(ll x, int i) { return x & ~(1LL << i); }

// Toggle i‑th bit
inline ll toggleBit(ll x, int i) { return x ^ (1LL << i); }

// Reverse bits of a 32‑bit number (GCC/Clang builtin)
inline uint32_t reverseBits(uint32_t x) { return __builtin_bitreverse32(x); }

// ----------- Common Patterns -----------

// 1. Count bits in range [L,R] with prefix technique (optional for large ranges)
int countBitsInRange(ll L, ll R) {
    // naive for demonstration – replace with DP if needed
    int ans = 0;
    for (ll x = L; x <= R; ++x) ans += popcntll(x);
    return ans;
}

// 2. Find missing number in [0..n] using XOR
ll findMissing(const vector<ll>& arr) {
    ll xorAll = 0, xorArr = 0;
    for (size_t i = 0; i <= arr.size(); ++i) xorAll ^= (ll)i; // 0..n
    for (ll v : arr) xorArr ^= v;
    return xorAll ^ xorArr;
}

// 3. Maximum XOR of two numbers in an array – using Trie (bit‑wise)
struct TrieNode {
    TrieNode* child[2] = {nullptr, nullptr};
};

void insertTrie(TrieNode* root, int num) {
    TrieNode* node = root;
    for (int i = 31; i >= 0; --i) {
        int b = (num >> i) & 1;
        if (!node->child[b]) node->child[b] = new TrieNode();
        node = node->child[b];
    }
}

int queryTrie(TrieNode* root, int num) {
    TrieNode* node = root;
    int maxXor = 0;
    for (int i = 31; i >= 0; --i) {
        int b = (num >> i) & 1;
        int want = b ^ 1; // opposite bit for maximizing XOR
        if (node->child[want]) {
            maxXor |= (1 << i);
            node = node->child[want];
        } else {
            node = node->child[b];
        }
    }
    return maxXor;
}

int maximumXOR(const vector<int>& a) {
    TrieNode* root = new TrieNode();
    for (int v : a) insertTrie(root, v);
    int best = 0;
    for (int v : a) best = max(best, queryTrie(root, v));
    return best;
}

// 4. Subset enumeration via bitmask (already known, included for completeness)
vector<vector<int>> enumerateSubsets(const vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> res;
    for (int mask = 0; mask < (1<<n); ++mask) {
        vector<int> cur;
        for (int i = 0; i < n; ++i) if (mask & (1<<i)) cur.push_back(arr[i]);
        res.push_back(move(cur));
    }
    return res;
}

// 5. Count subarrays with given XOR = K (using prefix XOR + hashmap)
int subarraysWithXor(const vector<int>& a, int K) {
    unordered_map<int,int> freq; // prefix XOR -> count
    freq[0] = 1;
    int pref = 0, ans = 0;
    for (int v : a) {
        pref ^= v;
        ans += freq[pref ^ K];
        ++freq[pref];
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Demo of a few utilities:
    ll x = 29; // 11101b
    cout << "popcnt(" << x << ") = " << popcntll(x) << '\n';
    cout << "isPowerOfTwo(" << x << ") = " << boolalpha << isPowerOfTwo(x) << '\n';
    cout << "lowest set bit of " << x << " = " << lowBit(x) << '\n';
    cout << "toggle 2nd bit: " << toggleBit(x,2) << '\n';

    // Example: maximum XOR in an array
    vector<int> arr = {3,10,5,25,2,8};
    cout << "Maximum XOR = " << maximumXOR(arr) << '\n';

    return 0;
}
```

## Time Complexity
- Individual bit helpers: `O(1)`.
- Popcount via builtin: `O(1)`.
- Subset enumeration: `O(2^n * n)` (exponential, expected for brute force).
- Maximum XOR using Trie: `O(N * 32)`.
- Subarray XOR count: `O(N)`.

## Space Complexity
- Helpers: `O(1)`.
- Trie for max XOR: `O(N * 32)` nodes.
- Subset enumeration: `O(2^n * n)` to store all subsets (optional, can output on the fly).

## Common Variations
- **Mask DP** – DP over bitmask states for traveling salesman, subset sum, etc.
- **Gray Code generation** – `i ^ (i>>1)` gives successive masks differing by one bit.
- **Bitwise DP on subsets** – iterate over sub‑masks using `for (int sub = mask; sub; sub = (sub-1) & mask)`.
- **Parity tricks** – using `x & 1` to check odd/even, `x ^ 1` to toggle parity.
- **Modular arithmetic with powers of two** – replace `% 2^k` with `& ((1<<k)-1)`.
- **Fast exponentiation with bit shifts** – binary exponentiation.
- **Counting bits in a range** – use DP on bits (digit DP) for large ranges.

## Common Mistakes
- Forgetting to cast to unsigned when shifting signed numbers (undefined behavior on right shift).
- Using `1 << i` with `i >= 31` on a 32‑bit `int` (overflow). Prefer `1LL << i` for safety.
- Not clearing the trie memory (leak) – in contests this is usually acceptable.
- Assuming `int` is 32‑bit on all platforms; use fixed‑width types (`int32_t`, `int64_t`).
- Mixing up 0‑based vs 1‑based indexing when extracting bits.

## Dry Run Example (Maximum XOR)
Array: `[3,10,5,25,2,8]`
- Insert all numbers into the trie.
- Query each number; the best pair is `5 ^ 25 = 28`.
- Output: `Maximum XOR = 28`.

## Interview Tips
- Mention built‑in intrinsics (`__builtin_popcount`, `__builtin_ctz`, `__builtin_clz`) – they are O(1) and often faster.
- When asked for “number of set bits”, discuss both builtin and manual Kernighan’s algorithm (`while(x){x &= x-1; ++cnt;}`).
- For “is power of two”, explain the `x && !(x & (x-1))` trick and edge‑case `x=0`.
- If the problem uses large limits (10^18), switch to `unsigned long long` and 64‑bit shifts.
- Demonstrate how bitmask DP reduces exponential states (`O(N * 2^N)`) and how to iterate over sub‑masks efficiently.

## Similar LeetCode Problems
- 191. Number of 1 Bits
- 231. Power of Two
- 260. Single Number III
- 421. Maximum XOR of Two Numbers in an Array
- 327. Count of Range Sum (uses prefix XOR trick for binary arrays)
- 1024. Video Stitching (bitmask DP variant)
- 198. House Robber (can be expressed as DP on subsets for small `n`)
- 1720. Number of Ways to Paint N × 3 Grid (bitmask DP)
- 1619. Mean of Array After Removing Some Elements (uses parity tricks)

---
*All code follows modern C++17 standards, includes comprehensive comments, and is ready to paste into a LeetCode‑style solution.*
