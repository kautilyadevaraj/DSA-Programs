//https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

class Solution {
    public:
      int minPlatform(vector<int>& arr, vector<int>& dep) {
          sort(arr.begin() , arr.end());
          sort(dep.begin() , dep.end());
          
          int i = 0, j = 0;
          
          int max_cnt = INT_MIN;
          int cnt = 0;
          while(i < arr.size()){
              if(arr[i] <= dep[j]){
                  cnt++;
                  i++;
              }
              
              else{
                  cnt--;
                  j++;
              }
              max_cnt = max(max_cnt , cnt);
          }
          
          return max_cnt;
      }
  };
  