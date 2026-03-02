#include <cstring>
int dp[100001][3];

// int solve(int prev , int idx , vector<vector<int>> &points){
//     if(idx >= points.size())
//         return 0;

//     int take_0 = 0;

//     if(prev == -1 || prev != 0){
//         if(dp[idx][prev + 1] != -1)
//             take_0 = dp[idx][prev + 1];
//         else
//             take_0 = points[idx][0] + solve(0 , idx + 1 , points);
//     }

//     int take_1 = 0;
//     if(prev == -1 || prev != 1){
//         if(dp[idx][prev + 1] != -1)
//             take_1 = dp[idx][prev + 1];
//         else
//             take_1 = points[idx][1] + solve(1 , idx + 1 , points);
//     }
        

//     int take_2 = 0;
//     if(prev == -1 || prev != 2){
//         if(dp[idx][prev + 1] != -1)
//             take_2 = dp[idx][prev + 1];
//         else
//             take_2 = points[idx][2] + solve(2 , idx + 1 , points);
//     }

//     return dp[idx][prev + 1] = max(take_0 , max(take_1 , take_2));
// }

int ninjaTraining(int n, vector<vector<int>> &points)
{
    memset(dp , -1 , sizeof(dp));

    dp[0][0] = points[0][0];
    dp[0][1] = points[0][1];
    dp[0][2] = points[0][2];

    for(int i = 1 ; i < n ; i++){
        dp[i][0] = points[i][0] + max(dp[i-1][1] , dp[i-1][2]);
        dp[i][1] = points[i][1] + max(dp[i-1][0] , dp[i-1][2]);
        dp[i][2] = points[i][2] + max(dp[i-1][1] , dp[i-1][0]);
    }

    return max(dp[n-1][0] , max(dp[n-1][1] , dp[n-1][2]));
}