class Solution {
    // long long dp[100001][2];
    // long long solve(int idx , bool isEven , vector<int>& nums){
    //     if(idx >= nums.size())
    //         return 0;

    //     if(dp[idx][isEven] != -1)
    //         return dp[idx][isEven];

    //     long long skip = solve(idx + 1 , isEven , nums);

    //     long long take = (isEven ? nums[idx] : -nums[idx]) + solve(idx + 1 , !isEven , nums);

    //     return dp[idx][isEven] = max(skip , take);
    // }
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        // memset(dp , -1 , sizeof(dp));
        // return solve(0 , true , nums);

        //bottom-up approach
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));

        for(int i = 1 ; i < n + 1 ; i++){
            dp[i][0] = max(dp[i - 1][1] - nums[i - 1] , dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][0] + nums[i - 1] , dp[i - 1][1]);
        }

        return max(dp[n][0] , dp[n][1]);
    }
};