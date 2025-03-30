class Solution {
    double timeRequired(vector<int>& dist, double hour, int speed){
        double time = 0;
        int i = 0;
        for(; i < dist.size() - 1 ; i++){
            time += ceil((double)dist[i]/speed);
        }
        time += (double)dist[i]/speed;
        return time;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1, high = pow(10, 7), ans = -1;

        while(low <= high){
            int mid = (low + high)/2;

            if(timeRequired(dist, hour, mid) > hour)
                low = mid + 1;
            else{ 
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};