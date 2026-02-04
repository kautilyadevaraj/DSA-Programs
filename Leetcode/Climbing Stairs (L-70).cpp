class Solution {
    //classic recursion (brute force)
    int F(int n){
        if(n < 0)
            return 0;

        if(n == 0)
            return 1;

        return F(n - 1) + F(n - 2);
    }

    int F(int n , vector<int>& dp){
        if(n < 0)
            return 0;

        if(n == 0)
            return 1;

        if(dp[n] != -1)
            return dp[n];

        return dp[n] = F(n - 1 , dp) + F(n - 2 , dp);
    }

public:
    int climbStairs(int n) {
        //Memoization
        // vector<int> dp(n + 1 , -1);

        // return F(n , dp);

        //Bottom up approach / tabulation
        if(n <= 2)
            return n;

        int a = 1;
        int b = 2;
        int c = 3;

        for(int i = 3 ; i <= n ; i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};