//https://www.naukri.com/code360/problems/print-longest-common-subsequence_8416383?leftPanelTabValue=PROBLEM

string findLCS(int n, int m,string &text1, string &text2){
    vector<vector<string>> dp(n + 1 , vector<string>(m + 1 , ""));

    for(int i = 1 ; i < n + 1 ; i++){
        for(int  j = 1 ; j < m + 1 ; j++){
            if(text1[i - 1] == text2[j - 1])
                dp[i][j] = text1[i - 1] + dp[i - 1][j - 1];

            else{
                if(dp[i][j - 1].size() >= dp[i - 1][j].size())
                    dp[i][j] = dp[i][j - 1];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
    }
    string ans = dp[n][m];
    reverse(ans.begin() , ans.end());
    return ans;	
}