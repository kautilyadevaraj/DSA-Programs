// recursion + memoization approach
class Solution {
    int func(int idx , vector<int>& nums, vector<int>& dp, int n){
        if(idx > n)
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int steal = nums[idx] + func(idx + 2 , nums , dp, n);

        int skip = func(idx + 1 , nums , dp, n);

        return dp[idx] = max(steal , skip);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
            return nums[0];

        if(n == 2)
            return max(nums[0] , nums[1]);
            
        vector<int> dp1(n + 1 , -1);
        vector<int> dp2(n + 1, -1);

        int take_0th_index = func(0 , nums , dp1 , n - 2);

        int take_1st_index = func(1 , nums , dp2 , n - 1);

        return max(take_0th_index , take_1st_index);
    }
};

//bottom up approach
class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            if(n == 1) return nums[0];
    
            vector<int> arr1(n);
            arr1[0] = 0;
            arr1[1] = nums[0];
    
            for(int i = 2 ; i < n ; i++){
                int idx = i - 1;
    
                arr1[i] = max(arr1[i - 2] + nums[idx] , arr1[i - 1]);
            }
    
            vector<int> arr2(n);
            arr2[0] = 0;
            arr2[1] = nums[1];
    
            for(int i = 2 ; i < n ; i++){
                int idx = i;
    
                arr2[i] = max(arr2[i - 2] + nums[idx] , arr2[i - 1]);
            }
    
            return max(arr1[n - 1] , arr2[n - 1]);
        }
    };

//constant space appraoch
class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            if(n == 1) return nums[0];
    
            int prev_steal1 = 0;
            int prev_skip1 = nums[0];
    
            for(int i = 1 ; i < n - 1 ; i++){
                int val = nums[i];
    
                int steal = prev_steal1 + val;
                int skip = prev_skip1;
    
                prev_skip1 = max(steal , skip);
                prev_steal1 = skip;
            }
    
            int prev_steal2 = 0;
            int prev_skip2 = nums[1];
    
            for(int i = 2 ; i < n ; i++){
                int val = nums[i];
    
                int steal = prev_steal2 + val;
                int skip = prev_skip2;
    
                prev_skip2 = max(steal , skip);
                prev_steal2 = skip;
            }
    
            return max(prev_skip1 , prev_skip2);
        }
    };