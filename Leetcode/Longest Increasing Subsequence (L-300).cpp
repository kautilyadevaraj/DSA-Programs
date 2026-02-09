class Solution {
    // int dp[2500][2501];
    // int solve(int prev_idx , int idx , vector<int>& nums){
    //     if(idx >= nums.size())
    //         return 0;

    //     if(dp[idx][prev_idx + 1] != -1) return dp[idx][prev_idx + 1];

    //     int take = 0;
    //     if(prev_idx == -1 || nums[idx] > nums[prev_idx])
    //         take = 1 + solve(idx , idx + 1 , nums);

    //     int skip = solve(prev_idx , idx + 1 , nums);

    //     return dp[idx][prev_idx + 1] = max(take , skip);
    // }
public:
    int lengthOfLIS(vector<int>& nums) {
        // memset(dp , -1 , sizeof(dp));
        // return solve(-1 , 0 , nums);

        //bottom up approach
        int n = nums.size();
        vector<int> dp(n , 1);
        int ans = 1;

        for(int i = 1 ; i < n ; i++){
            int max_length = 0;

            for(int j = 0 ; j < i ; j++){
                if(nums[j] < nums[i])
                    max_length = max(max_length , dp[j]);
            }

            if(max_length)
                dp[i] = 1 + max_length;
            
            ans = max(dp[i] , ans);
        }

        return ans;
    }
};