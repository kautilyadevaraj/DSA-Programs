class Solution {
    private:
    int calculateTotalHours(vector<int>& piles, int speed, int h){
        int ans = 0;

        for(int i = 0 ; i < piles.size() ; i++){
            ans += ceil((double)piles[i] / speed);
            if (ans > h) return 0;
        }

        return 1;      
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1 , high = *max_element(piles.begin() , piles.end());

        while(low <= high){
            int mid = (low + high)/2;

            int timeTaken = calculateTotalHours(piles, mid, h);

            if(timeTaken == 1) high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }
};