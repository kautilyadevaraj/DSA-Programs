class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = 0;
        int number = 0;
        
        while(zero < nums.size()){
            if(nums[number] != 0){
                number++;
                zero++;
            }
            else{
                if(number == zero || nums[zero] == 0)
                {
                    zero++;
                }
                else{
                    nums[number] = nums[zero];
                    nums[zero] = 0;
                    number++;
                    zero++;
                }
            }
        }
    }
};