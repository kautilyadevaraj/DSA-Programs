//https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1

class Solution {

    public:
      int minDifference(vector<int>& nums) {
          int sum = 0 , n = nums.size();
          
          for(int i : nums)
              sum += i;
          
          bool dp[n + 1][sum + 1];
          memset(dp , false , sizeof(dp));
  
          for(int i = 0 ; i < n + 1 ; i++)
              dp[i][0] = true;
  
          for(int i = 1 ; i < n + 1 ; i++){
              for(int j = 1 ; j < sum + 1 ; j++){
                  if(nums[i - 1] <= j)
                      dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                  else
                      dp[i][j] = dp[i - 1][j];
              }
          }
          
          // for(int j = 0 ; j < sum + 1 ; j++)
          //     cout << dp[n][j] << " ";
          
          int s1;
          for(int j = sum / 2 ; j >= 0 ; j--){
              if(dp[n][j] == true){
                  s1 = j;
                  break;
              }
          }
          
          return sum - 2 * s1;
      }
  };
  