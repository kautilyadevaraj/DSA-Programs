class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        vector<int> temp;
        //temporary array to store the k-elements which will be shifted to the beginning of the array
        for(int i = nums.size() - k ; i < nums.size() ; i++)
            temp.push_back(nums[i]);

        //modifying the original array to place the (n-k) elements into their original place
        for(int j = nums.size() - 1 ; j >= k ; j--)
            nums[j] = nums[j-k];
        
        //putting the elements of temp array back to original array
        for(int i = 0 ; i < temp.size() ; i++)
            nums[i] = temp[i];
    }
};