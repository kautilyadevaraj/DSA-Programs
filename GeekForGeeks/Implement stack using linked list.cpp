//https://www.geeksforgeeks.org/problems/implement-stack-using-linked-list/1
class MyStack {
    private:
      StackNode *top;
  
    public:
      void push(int x) {
          StackNode *newNode = new StackNode(x);
          newNode->next = top;
          top = newNode;
      }
  
      int pop() {
          if(top == NULL) return -1;
          else{
              StackNode *node = top;
              top = node->next;
              node->next = NULL;
              int x = node->data;
              delete node;
              return x;
          }
      }
  
      MyStack() { top = NULL; }
  };