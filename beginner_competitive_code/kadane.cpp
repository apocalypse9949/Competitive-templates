/*generic template*/
int curr = arr[0];
int ans = arr[0];

for(int i = 1; i < n; i++) {
    curr = max(arr[i], curr + arr[i]);
    ans = max(ans, curr);
}

return ans;
//_______________________________________________________________________
/*variant based looping*/
int curr = 0;
int ans = INT_MIN;

for(auto x : nums) {
    curr = max(x, curr + x);
    ans = max(ans, curr);
}

return ans;
