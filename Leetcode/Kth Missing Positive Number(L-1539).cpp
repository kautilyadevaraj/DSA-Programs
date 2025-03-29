class Solution {
    int noOfMiss(int index, int value){
        return value - (index + 1);
    }
public:
    int findKthPositive(vector<int>& arr, int k) {
        //Brute Force
        // for(int i = 0 ; i < arr.size() ; i++){
        //     if(arr[i] < k) k++;
        //     else break;
        // }

        // return k;

        //optimal Approach
        //edge cases
        int low = 0 , high = arr.size() - 1;
        
        while(low <= high){
            int mid  = (low + high)/2;

            if(k <= noOfMiss(mid, arr[mid]))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low + k;
    }
};