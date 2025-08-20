//https://www.naukri.com/code360/problems/stack-implementation-using-array_3210209
class Stack {
    int capacity, topIndex; 
    int *arr;
public:
    
    Stack(int capacity) : capacity(capacity), topIndex(-1) {
        arr = new int[capacity];
    }

    void push(int num) {
        if(topIndex < capacity - 1){
            arr[++topIndex] = num;
        }
    }

    int pop() {
        if(topIndex != -1){
            return arr[topIndex--];
        }
        else
            return -1;
    }
    
    int top() {
        if(topIndex != -1)
            return arr[topIndex];
        else return -1;
    }
    
    int isEmpty() {
        if (topIndex == -1) return 1;
        else return 0;
    }
    
    int isFull() {
        if(topIndex == capacity - 1) return 1;
        else return 0;
    }
    
};
