class Solution {
    public:
        int minCost(string colors, vector<int>& neededTime) {
            int ans = 0;
    
            for(int i = 1 ; i < colors.size() ; i++){
                if(colors[i] == colors[i - 1]){
                    int maxi = INT_MIN;
                    long long sum = neededTime[i - 1];
                    maxi = max(maxi , neededTime[i - 1]);
                    while(i <= colors.size() && colors[i] == colors[i - 1]){
                        sum += neededTime[i];
                        maxi = max(maxi , neededTime[i]);
                        i++;
                    }
                    ans += sum - maxi;
                }
            }
    
            return ans;
        }
    };