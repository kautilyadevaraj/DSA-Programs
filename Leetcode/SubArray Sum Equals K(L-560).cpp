class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        int prefixSum = 0 , cnt = 0;
        um[0] = 1;
        for(int i = 0 ; i < nums.size() ; i++){
            prefixSum += nums[i];

            if(um.find(prefixSum - k) != um.end()){
                cnt += um[prefixSum - k];
            }

            um[prefixSum] += 1;
        }

        return cnt;
    }
};