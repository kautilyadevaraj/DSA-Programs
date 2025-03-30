class Solution {
    bool check(vector<int>& position, int balls, int force){
        int cntBalls = 1, lastBall = position[0];

        for(int i = 0 ; i < position.size() ; i++){
            if(position[i] - lastBall >= force){
                cntBalls++;
                lastBall = position[i];
            }
            if(cntBalls >= balls) return true;
        }

        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin() , position.end());

        int low = 1, high = position[position.size() - 1] - position[0];

        while(low <= high){
            int mid = (low + high)/2;

            if(check(position, m, mid))
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high;
    }
};