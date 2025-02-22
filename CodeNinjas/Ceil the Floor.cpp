pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	pair<int, int> ans;
	int low = 0, high = n-1;

	while(low <= high){
		int mid = (low + high)/2;

		if(a[mid] == x)
			return {a[mid] , a[mid]};
		else if(x > a[mid])
			low = mid + 1;
		else	
			high = mid - 1;
	}

	ans.first = high == -1 || high == n ? -1 : a[high];
	ans.second = low == -1 || low == n ? -1 : a[low];
	return ans;
}