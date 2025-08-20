//https://www.naukri.com/code360/problems/queue-using-array-or-singly-linked-list_2099908?leftPanelTabValue=SUBMISSION
#include <bits/stdc++.h>
class Queue {
    int start;
    vector<int> arr;
public:
    Queue(): start(-1) {
        
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(arr.size() == 0) return true;
        else return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        arr.push_back(data);
    }

    int dequeue() {
        // Implement the dequeue() function
        if(arr.size() == 0) return -1;
        else{
            int ele = arr[0];
            arr.erase(arr.begin());
            return ele;
        }
    }

    int front() {
        // Implement the front() function
        if(arr.size() == 0) return -1;
        else return arr[0];
    }
};