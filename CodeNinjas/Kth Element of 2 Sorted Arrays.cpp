#include <climits>
int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    // Write your code here
    if(n > m) return kthElement(arr2 , arr1 , m , n , k);
    int low = max(0, k - m) , high = min(k, n);

    while(low <= high){
        int mid1 = (low + high)/2;
        int mid2 = k - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if(mid1 - 1 >= 0) l1 = arr1[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = arr2[mid2 - 1];

        if(mid1 < n) r1 = arr1[mid1];
        if(mid2 < m) r2 = arr2[mid2];

        if(l1 <= r2 && l2 <= r1){
            return max(l1, l2);
        }

        else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }

    return 0; //never reach here
}