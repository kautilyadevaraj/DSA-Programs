//https://www.naukri.com/code360/problems/lower-bound_8165382
int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
        int beg = 0;
        int end = n - 1;
        int ans = n;
        
        while(beg <= end){
            int mid = (beg + end)/2;
            
            if(arr[mid] >= x){
                ans = mid;
                end = mid - 1;
            }
            else
                beg = mid + 1;
        }

		return ans;
}

