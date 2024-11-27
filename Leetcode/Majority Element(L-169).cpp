class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Moore's voting algorithm
        int ele;
        int cnt = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            if(cnt == 0){
                ele = nums[i];
                cnt++;
            }
            else if(nums[i] == ele)
                cnt++;
            else
                cnt--;
        }

        return ele;
    }
};