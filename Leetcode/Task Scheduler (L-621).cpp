class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            if(n == 0)
                return tasks.size();
            
            vector<int> mp(26 , 0);
    
            for(char c : tasks){
                mp[c - 'A']++;
            }
    
            sort(mp.begin() , mp.end());
    
            int spaces = mp[25] - 1;
            int idle = spaces * n;
    
            for(int i = 24 ; i >= 0 ; i--){
                idle -= min(spaces , mp[i]);
            }
    
            if(idle <= 0) return tasks.size();
    
            return idle + tasks.size();
        }
    };