class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;

        while(low <= high){
            int mid = (low + high)/2;

            if(nums[mid] >= target) high = mid - 1;
            else low = mid + 1;
        }

        if (low == n || nums[low] != target){
            return {-1 , -1};
        }
        int start = low;
        high = n-1;
        while(low <= high){
            int mid = (low + high)/2;

            if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }

        return {start , high};
    }
};