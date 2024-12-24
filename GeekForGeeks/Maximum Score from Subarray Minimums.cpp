//https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/0?category
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        // Your code goes here
        int sum = INT_MIN;
        int p1 = 0 , p2 = 1;
        
        while(p2 < arr.size()){
            sum = max(sum , arr[p1]+arr[p2]);
            p1++;
            p2++;
        }
        
        return sum;
        
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        cout << ob.pairWithMaxSum(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends