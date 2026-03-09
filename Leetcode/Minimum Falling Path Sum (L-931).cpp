class Solution {
    // int dp[100][100];
    // int solve(int row , int col , vector<vector<int>>& matrix){
    //     if(col < 0 || col >= matrix.size())
    //         return INT_MAX;

    //         if(dp[row][col] != -1)
    //             return dp[row][col];

    //     if(row == matrix.size() - 1)
    //         return matrix[row][col];

    //      int left = solve(row + 1 , col - 1 , matrix);
    //      int down = solve(row + 1 , col , matrix);
    //      int right = solve(row + 1 , col + 1 , matrix);

    //      return dp[row][col] = matrix[row][col] + min(left , min(down , right));
    // }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // memset(dp , -1 , sizeof(dp));
        int n = matrix.size();

        // int mini = INT_MAX;
        // for(int i = 0 ; i < n ; i++){
        //     mini = min(mini , solve(0 , i , matrix));
        // }

        // return mini;

        //bottom up approach
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int i = 0 ; i < n ; i++){
            dp[n - 1][i] = matrix[n -1][i];
        }

        for(int i = n - 2 ; i >= 0 ; i--){
            for(int j = 0 ; j < n ; j++){
                int left = INT_MAX , right = INT_MAX;
                int down;

                if(j > 0)
                    left = dp[i + 1][j - 1];

                down = dp[i + 1][j];

                if(j < n - 1)
                    right = dp[i + 1][j + 1];

                dp[i][j] = matrix[i][j] + min(left , min(down , right));
            }
        }

        int mini = INT_MAX;
        for(int i = 0 ; i < n ; i++)
            mini = min(mini , dp[0][i]);

        return mini;
    }
};