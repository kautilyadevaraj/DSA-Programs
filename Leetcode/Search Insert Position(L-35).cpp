class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int beg = 0 , end = nums.size() - 1;
        int mid;
        int ans = nums.size();

        while(beg <= end){
            mid = (beg + end)/2;

            
            if(nums[mid] >= target){
                ans = mid;
                end = mid - 1;
            }
            else
                beg = mid + 1;
        }
        return ans;
    }
};