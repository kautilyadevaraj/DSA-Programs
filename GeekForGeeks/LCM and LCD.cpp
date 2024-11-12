//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long gcd(long long a , long long b)
    {
        if (b!=0)
        {
            return gcd(b, a%b);
        }
        
        return a;
    }

    vector<long long> lcmAndGcd(long long a, long long b) {
        // code here
        vector<long long> v(2);
        v[1] = gcd(a, b);
        v[0] = (a*b)/v[1];
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A, B;

        cin >> A >> B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A, B);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends