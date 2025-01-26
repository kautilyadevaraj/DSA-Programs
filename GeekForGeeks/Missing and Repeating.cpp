//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        // long long S = 0;
        // long long SN = 0;
        // long long S2 = 0;
        // long long S2N = 0;
        // long long n = arr.size();
        // for(int i = 0 ; i < n ; i++){
        //     S += arr[i];
        //     S2 += (arr[i] * arr[i]);
        // }
        
        // SN = (n*(n + 1))/2;
        // S2N = (n * (n + 1) * (2*n + 1))/6;
        
        // //X-Y
        // long long val1 = S - SN;
        // long long val2 = S2 - S2N;
        // val2 = val2 / val1;
        
        // long long X = (val1 + val2)/2;
        // long long Y = X - val1;
        // return {(int)X , (int)Y};
        
        long long n = arr.size();
        int xr = 0;
        
        for(int i = 0 ; i < n ; i++) {
            xr ^= arr[i];
            xr ^= (i+1);
        }
        
        int bitNo = 0;
        
        while(1){
            if((xr & (1 << bitNo)) != 0) break;
            bitNo++;
        }
        
        int zero = 0;
        int one = 0;
        
        for(int i = 0 ; i < n ; i++){
            if((arr[i] & (1<<bitNo)) != 0)
                one ^= arr[i];
            else
                zero ^= arr[i];
        }
        
        for(int i = 1 ; i <= n ; i++){
            if((i & (1<<bitNo)) != 0)
                one ^= i;
            else
                zero ^= i;
        }
        
        int cnt = 0;
        for(int i = 0 ; i < n ; i++)
            if(arr[i] == zero) return{zero , one};
        
        return {one , zero};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends