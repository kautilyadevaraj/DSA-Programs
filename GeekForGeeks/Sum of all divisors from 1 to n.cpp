//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long sumOfDivisors(int n) {
        // Write Your Code here
        long long sum = 0;
        
        for (int i = 1; i <= n; i++) {
            // Add i to the sum for each multiple of i up to n
            //Example for n = 4
            //1 is a divisor of 1,2,3,4..therefore value contributed by 1 is 1*4 = 4
            //2 is a divisor of 2 and 4, so value contribtued by 2 is 2*2 = 4
            //3 is divisor of 3 itself, so value contirbuted by 3 is 3*1 = 3
            //4 is divisor of itself, so value contributed by 4 is 4*1 = 4
            sum += i * (n / i);
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        long long ans = ob.sumOfDivisors(N);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends