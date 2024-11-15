class Solution {
public:
    bool check(vector<int>& nums) {
        int pairs = 0;

        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] < nums[i-1])
                pairs++;
        }
        if(nums[nums.size() - 1] > nums[0])
            pairs++;
        cout << pairs;
        return pairs == 1 || pairs == 0;
    }
};