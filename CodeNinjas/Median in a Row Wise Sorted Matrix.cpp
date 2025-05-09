//https://www.naukri.com/code360/problems/median-of-a-row-wise-sorted-matrix_1115473

int upperBound(vector<int> &arr, int x, int n){	
        int beg = 0;
        int end = n - 1;
        int ans = n;
        
        while(beg <= end){
            int mid = (beg + end)/2;
            
            if(arr[mid] > x){
                ans = mid;
                end = mid - 1;
            }
            else
                beg = mid + 1;
        }

		return ans;
}

int countSmallEquals(vector<vector<int>> &matrix, int m, int n, int x){
    int cnt = 0;

    for(int i = 0 ; i < m ; i++){
        cnt += upperBound(matrix[i] , x , n);
    }
    
    return cnt;
}

int median(vector<vector<int>> &matrix, int m, int n) {
    int low = INT_MAX, high = INT_MIN;
    
    for(int i = 0 ; i < m ; i++){
        low = min(low , matrix[i][0]);
        high = max(high , matrix[i][n - 1]);
    }

    int median = (n * m)/2;

    while(low <= high){
        int mid = (low + high)/2;

        if(countSmallEquals(matrix , m , n , mid) <= median) low = mid + 1;
        else high = mid - 1;
    }

    return low;
}