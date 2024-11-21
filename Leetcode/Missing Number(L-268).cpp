class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int originalSum = (nums.size() * (nums.size() + 1))/2;
        int foundSum = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            foundSum += nums[i];
        }

        return originalSum - foundSum;
    }
};