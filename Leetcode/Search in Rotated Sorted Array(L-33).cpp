class Solution {
public:
    int search(vector<int>& a, int x) {
        int low = 0, high = a.size() - 1;

        while(low <= high){
            int mid = (low + high)/2;

            if(a[mid] == x) return mid;

            //Finding the Sorted Half of the array
            //Left Sorted
            else if(a[low] <= a[mid]){
                if(a[low] <= x && x <= a[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            //Right Sorted
            else{
                if(a[mid] <= x && x <= a[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};