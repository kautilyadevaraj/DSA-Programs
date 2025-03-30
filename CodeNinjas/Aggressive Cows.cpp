bool check(vector<int> &stalls, int cows, int distance){
    int cntCows = 1, lastCow = stalls[0];

    for(int i = 0; i < stalls.size() ; i++){
        if(stalls[i] - lastCow >= distance)
        {
            cntCows++;
            lastCow = stalls[i];
        }
        if(cntCows >= cows) return true;
    }

    return false;
}


int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[stalls.size() - 1] - stalls[0];

    while(low <= high){
        int mid = (low + high)/2;

        if(check(stalls, k, mid))
            low = mid + 1;
        else
            high = mid - 1;
    }

    return high;
}