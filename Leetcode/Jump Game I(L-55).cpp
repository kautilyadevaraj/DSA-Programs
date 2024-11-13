class Solution {
public:
    bool canJump(vector<int>& nums) {
        //variable to keep track of the maximum index reachable at a given instance
        int max_index = 0;
        for(int i = 0 ; i < nums.size() ; i++){

            //if the current index goes above the max_index, it means u can never reach the end
            if (i > max_index) return false;

            max_index = max(max_index , i + nums[i]);
        }
        return true;
    }
};