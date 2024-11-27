//https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int left = 0, right = 0;
    long long sum = 0;
    int longest = 0;

    while (right < a.size()) {
        // Expand the window by adding the current element
        sum += a[right];

        // Shrink the window until sum <= k
        while (sum > k && left <= right) {
            sum -= a[left];
            left++;
        }

        // Check if the current window's sum equals k
        if (sum == k) {
            longest = max(longest, right - left + 1);
        }

        // Move the right pointer to expand the window
        right++;
    }

    return longest;
}
