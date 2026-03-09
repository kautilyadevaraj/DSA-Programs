class Solution {
    // int solve(int row , int col , vector<vector<int>>& triangle , vector<vector<int>>& dp){
    //     if(row == triangle.size() - 1)
    //         return triangle[row][col];

    //     if(dp[row][col] != -1)
    //         return dp[row][col];

    //     int left = solve(row + 1 , col , triangle , dp);
    //     int right = solve(row + 1 , col + 1 , triangle , dp);

    //     return dp[row][col] = triangle[row][col] + min(left , right);
    // }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        dp[0][0] = triangle[0][0];

        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < triangle[i].size() ; j++){
                int top = INT_MAX;
                int dia = INT_MAX;
                //for the element right above it
                if(j < triangle[i].size() - 1)
                    top = dp[i - 1][j];
                
                //for the element diagonally upward(left)
                if(j > 0)
                    dia = dp[i - 1][j - 1];

                dp[i][j] = triangle[i][j] + min(top , dia);
            }
        }

        int mini = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            mini = min(mini , dp[n - 1][i]);
        }

        return mini;
    }
};