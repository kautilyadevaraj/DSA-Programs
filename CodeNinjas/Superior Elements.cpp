//https://www.naukri.com/code360/problems/superior-elements_6783446

vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    int leader = a[a.size() - 1];
    vector<int> result;
    result.push_back(leader);
    for(int i = a.size() - 2 ; i >= 0 ; i--){
        if(a[i] > leader){
            result.push_back(a[i]);
            leader = a[i];
        }
    }

    return result;
}