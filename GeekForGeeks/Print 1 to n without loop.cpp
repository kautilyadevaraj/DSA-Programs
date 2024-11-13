//https://www.geeksforgeeks.org/problems/print-1-to-n-without-using-loops-1587115620/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    void printNos(int n) {
        // Your code here
        if (n == 0) return;
        printNos(n-1);
        cout << n;
        cout << " ";
    }
};

//{ Driver Code Starts.
/* Driver program to test printNos */
int main() {
    int T;

    // taking testcases
    cin >> T;

    while (T--) {
        int N;

        // input N
        cin >> N;
        Solution ob;
        // calling printNos() function
        ob.printNos(N);
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends