class Solution {
    int findMaxIndex(vector<vector<int>>& mat, int col){
        int max_ele = INT_MIN;
        int index = -1;

        for(int i = 0 ; i < mat.size() ; i++){
            if(mat[i][col] > max_ele){
                max_ele = mat[i][col];
                index = i;
            }
        }

        return index;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0 , high = mat[0].size() - 1;

        while(low <= high){
            int mid = (low + high)/2;

            int maxEleIndex = findMaxIndex(mat , mid);
            int left = mid - 1 >= 0 ? mat[maxEleIndex][mid - 1] : -1;
            int right = mid + 1 < mat[0].size() ? mat[maxEleIndex][mid + 1] : -1;

            if(left < mat[maxEleIndex][mid] && mat[maxEleIndex][mid] > right)
                return {maxEleIndex , mid};
            else if(left > mat[maxEleIndex][mid]) high = mid - 1;
            else low = mid + 1;
        }

        return {-1 , -1};
    }
};