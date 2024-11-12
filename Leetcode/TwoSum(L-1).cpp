class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //create a hash map of value->index
        map<int , int> hash;

        for(int i = 0 ; i < nums.size() ; i++){
            //if a+b = target, then target-b = a and thats what you are checking in this condition
            if(hash.find(target - nums[i]) != hash.end())
                return {hash[target - nums[i]] , i};

                hash[nums[i]] = i;       
        }
        return {};
    }
};