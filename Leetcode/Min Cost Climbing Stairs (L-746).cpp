class Solution {
    // int dp[1000];
    // int solve(int idx , vector<int>& cost){
    //     if(idx >= cost.size())
    //         return 0;

    //     if(dp[idx] != -1) return dp[idx];

    //     int step_one = solve(idx + 1 , cost);

    //     int step_two = solve(idx + 2 , cost);

    //     return dp[idx] = cost[idx] + min(step_one , step_two);
    // }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // memset(dp , -1 , sizeof(dp));
        // return min(solve(0 , cost) , solve(1 , cost));

        //bottom-up approach
        int n = cost.size();
        vector<int> dp(n + 1);

        dp[0] = 0;
        dp[1] = cost[0];

        for(int i = 2 ; i < dp.size() ; i++){
            int val = cost[i - 1];

            dp[i] = val + min(dp[i - 1] , dp[i - 2]);
        }

        return min(dp[n] , dp[n - 1]);
    }
};