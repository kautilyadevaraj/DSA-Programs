class Solution {
public:
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i = 1 ; i <= numRows ; i++){
            vector<int> row;
            int ans = 1;
            row.push_back(1);
            for(int j = 1 ; j < i ; j++){
                ans *= (i - j);
                ans /= j;
                row.push_back(ans);
            }
            result.push_back(row);
        }

        return result;
    }
};