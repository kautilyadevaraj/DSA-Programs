class Solution {
    // int dp[201][10001];
    // int solve(int idx , int target , vector<int>& nums){
    //     if(target == 0)
    //         return dp[idx][target] = true;
    //     if(idx < 0)
    //         return false;

    //     if(dp[idx][target] != -1) return dp[idx][target];

    //     bool take = false;
    //     if(target >= nums[idx])
    //         take = solve(idx - 1 , target - nums[idx] , nums);

    //     bool skip = solve(idx - 1 , target , nums);

    //     return dp[idx][target] = take || skip;
    // }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for(int n : nums)
            sum += n;

        if(sum % 2 != 0)
            return false;

        int n = nums.size();
        int target = sum / 2;
        // memset(dp , -1 , sizeof(dp));

        vector<vector<bool>> dp(n + 1 , vector<bool>(target + 1 , false));

        for(int i = 0 ; i < n + 1 ; i++)
            dp[i][0] = true;

        for(int idx = 1 ; idx < n + 1 ; idx++){
            for(int j = 1 ; j < target + 1 ; j++){
                bool take = false;
                if(j >= nums[idx - 1])
                    take = dp[idx - 1][j - nums[idx - 1]];

                bool skip = dp[idx - 1][j];

                dp[idx][j] = take || skip;
            }
        }

        // return solve(n - 1 , sum / 2 , nums);
        return dp[n][target];
    }
};