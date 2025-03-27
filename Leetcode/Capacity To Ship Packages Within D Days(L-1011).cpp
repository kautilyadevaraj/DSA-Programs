class Solution {
    bool isPossibleToLoad(vector<int>& weights, int capacity, int days){
        int day = 1, load = 0;

        for(int i = 0 ; i < weights.size() ; i++){
            if(day > days) return false;
            if(load + weights[i] > capacity)
            {
                day++;
                load = weights[i];
            }
            else
                load += weights[i];
        }
        if(day > days) return false;
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin() , weights.end()) , high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high){
            int mid = (low + high)/2;

            if(isPossibleToLoad(weights, mid, days))
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};