class Solution {
    private:
    int possible(vector<int>& arr, int day, int m, int k){
        int bouquets = 0, cnt = 0;

        for(int i = 0 ; i< arr.size() ; i++){
            if(arr[i] <= day)
                cnt++;
            else{
                bouquets += (cnt/k);
                cnt = 0;
            }
        }
        bouquets += (cnt/k);
        if(bouquets < m) return -1;
        return bouquets;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < (long long)m*k) return -1;
        int low = *min_element(bloomDay.begin() , bloomDay.end()) , high = *max_element(bloomDay.begin() , bloomDay.end());

        while(low <= high){
            int mid = (low + high)/2;

            int ans = possible(bloomDay, mid, m, k);
            if(ans == -1)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
};