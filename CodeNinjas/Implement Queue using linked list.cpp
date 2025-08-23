//https://www.naukri.com/code360/problems/implement-queue-using-linked-list_8161235
/**
 * Definition of linked list
 * class Node {
 * 
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 * 
 * Definition of Queue
 * struct Queue {
 *   Node* front;
 *   Node* rear;
 *   void push(int);
 *   int pop();
 *   
 *   Queue() {
 *       front = rear = NULL;
 *   }
 * };
 */

 void Queue::push(int x) {
    Node *newNode = new Node(x);
    if(rear == NULL){
        rear = newNode;
        front = newNode;
    }
    else{
        rear->next = newNode;
        rear = rear->next;
    }
}

int Queue::pop() {
    if(front == NULL) return -1;

    Node *deleteNode = front;
    front = front->next;
    int value = deleteNode->data;
    delete deleteNode;
    if(front == NULL) rear = nullptr;
    return value;
}