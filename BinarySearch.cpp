int left = 0;
int right = n - 1;

while (left <= right) {

    int mid = left + (right - left) / 2;

    if (found)
        return mid;

    else if (go_right)
        left = mid + 1;

    else
        right = mid - 1;
}
/*Binary Search Recognition Checklist

Use binary search when:

1. Array is sorted
Search in sorted array
2. Problem asks for
minimum possible
maximum possible
smallest valid
largest valid

Often binary search on answer.

3. Predicate is monotonic

Example:

Speed = 3 → impossible
Speed = 4 → impossible
Speed = 5 → possible
Speed = 6 → possible
Speed = 7 → possible

Once it becomes possible, it stays possible.

That's a binary-search-on-answer signal.

Memory Trick

For exact search:

while(left <= right)

For answer search / lower bound:

while(left < right)

And always remember:

mid = left + (right - left) / 2;

This is the standard binary search template used in most interview problems.*/
