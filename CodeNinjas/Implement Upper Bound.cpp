//https://www.naukri.com/code360/problems/implement-upper-bound_8165383
int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.	
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