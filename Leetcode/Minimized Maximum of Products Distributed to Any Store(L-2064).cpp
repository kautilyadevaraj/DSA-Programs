class Solution {
    bool possible(vector<int>& quantites, int stores, int maxCapacity){
        int store = 0;

        for(int i = 0 ; i < quantites.size() ; i++){
            store += quantites[i] / maxCapacity;
            if(quantites[i] % maxCapacity) store++;
            if(store > stores) return false;
        }
        return true;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = *max_element(quantities.begin(), quantities.end());

        while(low <= high){
            int mid = (low + high)/2;

            if(possible(quantities, n, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};