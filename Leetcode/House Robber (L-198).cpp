class Solution {
    // int func(int idx , vector<int>& nums, vector<int>& dp){
    //     if(idx >= nums.size())
    //         return 0;

    //     if(dp[idx] != -1)
    //         return dp[idx];

    //     int steal = nums[idx] + func(idx + 2 , nums , dp);

    //     int skip = func(idx + 1 , nums , dp);

    //     return dp[idx] = max(steal , skip);
    // }
public:
    int rob(vector<int>& nums) {
        //memoization approach
        // vector<int> dp(nums.size() + 1 , -1);
        // return func(0 , nums , dp);

        //bottom up approach
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> arr(n + 1);
        arr[0] = 0;
        arr[1] = nums[0];

        for(int i = 2 ; i <= n ; i++){
            int idx = i - 1;

            arr[i] = max(arr[i - 2] + nums[idx] , arr[i - 1]);
        }

        return arr[n];
    }
};