class Solution {
    int sumOfDivisors(vector<int>& nums, int div, int threshold){
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += ceil((double)nums[i]/div);
            if(sum > threshold) return -1;
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1 , high = *max_element(nums.begin() , nums.end());

        while(low <= high){
            int mid = (low + high)/2;

            if(sumOfDivisors(nums, mid, threshold) == -1)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
};