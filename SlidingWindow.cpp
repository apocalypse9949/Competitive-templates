/*How to Recognize Sliding Window Problems
Longest subarray
Shortest subarray
Maximum length
Minimum length
Continuous/contiguous subarray
Substring
At most K
Exactly K
Sum ≤ K
Sum ≥ K*/
//Generic Sliding Window Template
int left = 0;

for (int right = 0; right < n; right++) {

    // Include nums[right] in the window

    while (window_is_invalid) {

        // Remove nums[left] from the window

        left++;
    }

    // Update answer using window [left, right]
}
//_______________________________________________________________________
//Longest Subarray / Longest Substring Template
int left = 0;
int ans = 0;

for (int right = 0; right < n; right++) {

    // Add nums[right]

    while (invalid_window) {

        // Remove nums[left]

        left++;
    }

    ans = max(ans, right - left + 1);
}

return ans;
________________________________________________________________________________
/*Minimum Window Template

Used for:

Minimum Size Subarray Sum
Minimum Window Substring*/
int left = 0;
int ans = INT_MAX;

for (int right = 0; right < n; right++) {

    // Expand window

    while (valid_window) {

        ans = min(ans, right - left + 1);

        // Shrink window

        left++;
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Example: Longest Substring Without Repeating Characters
int left = 0;
unordered_set<char> st;
int ans = 0;

for (int right = 0; right < s.size(); right++) {

    while (st.count(s[right])) {
        st.erase(s[left]);
        left++;
    }

    st.insert(s[right]);

    ans = max(ans, right - left + 1);
}
