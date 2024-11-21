class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; i++){
            int end = i;

            while(end < nums.size() && nums[end] == nums[i])
                end++;
            if(end != i)
                nums.erase(nums.begin() + i + 1 , nums.begin() + end);
        }

        return nums.size();
    }
};