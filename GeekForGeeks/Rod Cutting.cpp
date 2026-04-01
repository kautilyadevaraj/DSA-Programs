// User function Template for C++
//https://www.geeksforgeeks.org/problems/rod-cutting0840/1
class Solution {
    // int dp[1001][1001];
    // int solve(int idx , int length , vector<int> &price){
    //     if(length == 0 || idx < 0)
    //         return 0;
            
        
    //     if(dp[idx][length] != -1)
    //         return dp[idx][length];
        
    //     int take = 0 , skip = 0;
    //     if(idx + 1 <= length)
    //         take = price[idx] + solve(idx , length - (idx + 1) , price);
        
    //     skip = solve(idx - 1 , length , price);
        
    //     return dp[idx][length] = max(take , skip);
    // }
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        // memset(dp , -1 , sizeof(dp));
        // return solve(n - 1 , n , price);
        
        vector<vector<int>> dp(n + 1 , vector<int>(n + 1 , 0));
        
        for(int i = 1 ; i < n + 1 ; i++){
            for(int j = 1 ; j < n + 1 ; j++){
                int take = 0 , skip = 0;
                if(i <= j)
                    take = price[i - 1] + dp[i][j - i];
                    
                skip = dp[i - 1][j];
                
                dp[i][j] = max(take , skip);
            }
        }
        
        return dp[n][n];
    }
};