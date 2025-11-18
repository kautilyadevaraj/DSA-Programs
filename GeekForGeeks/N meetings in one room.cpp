//https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class Solution {
    struct Data{
        int start, end;
    };
    
    static bool cmp(const Data &a, const Data &b) {
        return a.end < b.end;
    }
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<Data> arr(start.size());
        
        for(int i = 0 ; i < start.size() ; i++){
            arr[i].start = start[i];
            arr[i].end = end[i];
        }
        
        sort(arr.begin(), arr.end(), cmp);
        
        int ans = 0;
        int freeTime = -1;
        
        for(int i = 0 ; i < arr.size() ; i++){
            if(arr[i].start > freeTime){
                ans++;
                freeTime = arr[i].end;
            }
        }
        
        return ans;
    }
};