//Opposite Ends (Sorted Array)
int left = 0;
int right = nums.size() - 1;

while (left < right) {
    int sum = nums[left] + nums[right];

    if (sum == target) {
        // found answer
        break;
    }
    else if (sum < target) {
        left++;
    }
    else {
        right--;
    }
}
//_______________________________________________________________________________________

int left = 0;
int right = n - 1;

while (left < right) {
    // process

    if (condition)
        left++;
    else
        right--;
}
