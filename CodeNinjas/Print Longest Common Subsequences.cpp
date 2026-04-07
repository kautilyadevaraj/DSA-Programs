//https://www.naukri.com/code360/problems/print-longest-common-subsequence_8416383?leftPanelTabValue=PROBLEM

string findLCS(int n, int m,string &text1, string &text2){
    vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 0));

    for(int i = 1 ; i < n + 1 ; i++){
        for(int  j = 1 ; j < m + 1 ; j++){
            if(text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = max(dp[i][j - 1] , dp[i - 1][j]);
        }
    }

    int i = n, j = m;
    string ans = "";

    while(i > 0 && j > 0){
        if(text1[i - 1] == text2[j - 1]){
            ans += text1[i - 1];
            i--;
            j--;
        }

        else if(dp[i][j - 1] > dp[i - 1][j])
            j--;
        else    
            i--;
    }

    reverse(ans.begin() , ans.end());

    return ans;
}