class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Brute Force (O(N^2))
        // for(int i = 0 ; i < nums.size() ; i++){
        //     int min = i;
        //     for(int j = i + 1 ; j < nums.size() ; j++){
        //         if(nums[j] < nums[min])
        //             min = j;
        //     }
        //     if(min != i){
        //         int temp = nums[min];
        //         nums[min] = nums[i];
        //         nums[i] = temp;
        //     }
        // }
        //Slightly better approach is to sort it (O(N logN))

        //Optimal Approach is , have three variables and count number of occurances of each number. then again iterate till each variable ka value and replace with that number (O(2N))

        //Best Approach - Dutch National Flag Algorithm O(N)
        int low = 0 , mid = 0;
        int high = nums.size() - 1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low] , nums[mid]);
                low++;
                mid++;
            }

            else if(nums[mid] == 1)
                mid++;
            else{
                swap(nums[high] , nums[mid]);
                high--;
            }
        }
    }
};