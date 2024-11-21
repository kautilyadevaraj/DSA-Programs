class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int counter = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 1){
                counter++;
            }
            else{
                if(counter > count)
                    count = counter;
                counter = 0;
            }
        }
        return counter > count ? counter : count;
    }
};