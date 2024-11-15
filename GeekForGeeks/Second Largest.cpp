//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int max = arr[0];
        int max2 = INT_MIN;
        
        for(int i = 1 ; i < arr.size() ; i++){
            if(arr[i] > max){
                max2 = max;
                max = arr[i];
            }
            else if (arr[i] > max2 && arr[i] != max) 
                max2 = arr[i];
        }
        return (max2 == INT_MIN) ? -1 : max2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends