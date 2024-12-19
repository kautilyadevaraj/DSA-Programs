/*1838. Frequency of the Most Frequent Element
Solved
Medium
Topics
Companies
Hint
The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.*/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());

        long left = 0 , right = 0;
        long result = 0, sum = 0;
        while(right < nums.size()){
            sum += nums[right];
            while(nums[right] * (right-left+1) > k + sum){ //finding a valid window
                sum -= nums[left];
                left++;
            }
            
            result = max(result , right - left + 1);
            right++;
        }

        return result;
    }
};