//https://www.naukri.com/code360/problems/allocate-books_1090540

bool possible(vector<int>& arr, int students, int maxPages){
    int stud = 1 , currentSize = 0; 

    for(int i = 0 ; i < arr.size() ; i++){
        if(currentSize + arr[i] > maxPages){
            currentSize = arr[i];
            stud++;
        }
        else
            currentSize += arr[i];

        if(stud > students) return false;
    }
    return true;
}


int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m > n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low <= high){
        int mid = (low + high)/2;

        if(possible(arr, m, mid))
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low;
}