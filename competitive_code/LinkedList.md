# Linked List

## When to Use
- Problems involving sequential nodes with next pointers, often requiring O(1) insert/delete at arbitrary positions.

## Recognition Patterns
- "Reverse a linked list", "Detect cycle", "Remove N-th node from end", "Merge two sorted lists".

## Core Idea
Traverse using a pointer (`curr`), manipulate `next` pointers to achieve the desired transformation. Use a dummy head to simplify edge cases.

## Generic Template Code (C++17)
```cpp
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Example: reverse a singly linked list
ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr; // update answer / state
    while (head) { // process current element
        ListNode* nxt = head->next; // move pointers
        head->next = prev; // update link
        prev = head; // move pointers
        head = nxt; // move pointers
    }
    return prev; // new head
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Build list from input (placeholder)
    int n; cin>>n; ListNode* dummy = new ListNode(0); ListNode* cur = dummy;
    for(int i=0;i<n;++i){int x;cin>>x; cur->next = new ListNode(x); cur=cur->next;}
    ListNode* newHead = reverseList(dummy->next);
    for(ListNode* p=newHead; p; p=p->next) cout<<p->val<<' '; cout<<"\n";
    return 0;
}
```

## Time Complexity
`O(N)` – single pass.

## Space Complexity
`O(1)` auxiliary.

## Common Variations
- Detect cycle (Floyd's tortoise‑hare).
- Merge two sorted lists.
- Remove duplicate nodes.

## Common Mistakes
- Losing the rest of the list when re‑linking (store `next` first).
- Forgetting to handle empty list (`nullptr`).
- Memory leaks – delete nodes if not needed.

## Dry Run Example
List: `1->2->3` → after reversal `3->2->1`.

## Interview Tips
- Use a dummy node to avoid special‑case head handling.
- Explain time/space and why no extra data structures are needed.
- Discuss converting recursion to iteration for large lists.

## Similar LeetCode Problems
1. 206. Reverse List
2. 141. Linked List Cycle
3. 19. Remove Nth Node From End of List
```
