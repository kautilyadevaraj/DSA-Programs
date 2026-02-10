class Solution {
    // int dp[1000][1001];
    static bool cmp(vector<int>& pair1 , vector<int>& pair2){
        return pair1[0] < pair2[0];
    }

    // int solve(int prev , int idx , vector<vector<int>>& pairs){
    //     if(idx >= pairs.size())
    //         return 0;

    //     if(dp[idx][prev + 1] != -1)
    //         return dp[idx][prev + 1];

    //     int take = 0;
    //     if(prev == -1 || pairs[prev][1] < pairs[idx][0])
    //         take = 1 + solve(idx , idx + 1 , pairs);

    //     int skip = solve(prev , idx + 1 , pairs);

    //     return dp[idx][prev + 1] = max(take , skip);
    // }

public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin() , pairs.end() , cmp);

        // memset(dp , -1 , sizeof(dp));

        // return solve(-1 , 0 , pairs);
        int n = pairs.size();

        vector<int> dp(n , 1);
        int ans = 1;

        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(pairs[j][1] < pairs[i][0])
                    dp[i] = max(dp[i] , 1 + dp[j]);
            }

            ans = max(ans , dp[i]);
        }

        return ans;
    }
};