class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_num = INT_MIN;
        int prefix = 1;
        int suffix = 1;

        for(int i = 0 ; i < nums.size() ; i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix *= nums[i];
            suffix *= nums[nums.size() - i - 1];
            max_num = max(max_num , max(prefix , suffix));
        }

        
        return max_num;
    }
};