class Solution {
    public:
        vector<bool> prefixesDivBy5(vector<int>& nums) {
            vector<bool> result(nums.size());
    
            int curr = 0;
    
            for(int i = 0 ; i < nums.size() ; i++){
                curr = ((curr * 2) + nums[i]) % 5;
                //multiplying by 2 because for each element we are left shifting elements by one place
                //after shifting by one, we add the nums[i]
                //have done a mod 5 to prevent integer overflow
                result[i] = curr == 0;
            }
    
            return result;
        }
    };