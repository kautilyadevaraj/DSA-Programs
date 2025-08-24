//https://www.naukri.com/code360/problems/next-greater-element_1112581
#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> ans = arr;

    for(int i = arr.size() - 1 ; i >= 0 ; i--){
        while(!st.empty() && st.top() >= arr[i])
            st.pop();
        
        if(st.empty()) 
            ans[i] = -1;
        else
            ans[i] = st.top();
        st.push(arr[i]);
    }

    return ans;
}