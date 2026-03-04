class Solution {
    // int dp[101][101];
    // int solve(int row , int col , vector<vector<int>>& obstacleGrid){
    //     if(row >= obstacleGrid.size() || col >= obstacleGrid[0].size() || row < 0 || col < 0 || obstacleGrid[row][col] == 1)
    //         return 0;

    //     if(row == obstacleGrid.size() - 1 && col ==  obstacleGrid[0].size() - 1)
    //         return 1;

    //     if(dp[row][col] != -1)
    //         return dp[row][col];
    //     return dp[row][col] = solve(row , col + 1 , obstacleGrid) + solve(row + 1 , col , obstacleGrid);
    // }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;

        int dp[m][n];
        memset(dp , 0 , sizeof(dp));
        // return solve(0 , 0 , obstacleGrid);
        dp[0][0] = 1;
        
        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(obstacleGrid[row][col] == 1)
                    continue;
                int up = 0;
                int left = 0;
                if(row > 0)
                    up = dp[row - 1][col];
                if(col > 0)
                    left = dp[row][col - 1];

                dp[row][col] += up + left;
            }
        }

        return dp[m - 1][n - 1];
    }
};