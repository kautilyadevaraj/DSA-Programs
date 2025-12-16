//https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    bool isLeaf(Node *root){
        return root->left == NULL && root->right == NULL;
    }
    
    void addLeftBoundaryNodes(Node *root, vector<int>& ans){
        ans.push_back(root->data);
        if(root->left) root = root->left;
        else
            return;
        while(root){
            if(isLeaf(root))
                break;
            
            ans.push_back(root->data);
            
            if(root->left) root = root->left;
            else root = root->right;
        }
    }
    
    void addRightBoundaryNodes(Node *root, vector<int>& ans){
        if(isLeaf(root)) return;
        
        if(root->right) root = root->right;
        else return;
        
        stack<int> st;
        
        while(root){
            if(isLeaf(root)) break;
            
            st.push(root->data);
            
            if(root->right) root = root->right;
            else root = root->left;
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
    }
    
    void addLeafNodes(Node *root, vector<int>& ans){
        if(root == NULL) return;
        
        if(isLeaf(root)) ans.push_back(root->data);
        addLeafNodes(root->left, ans);
        addLeafNodes(root->right, ans);
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(root == NULL) return ans;
        if(isLeaf(root)) return {root->data};
        
        addLeftBoundaryNodes(root , ans);
        addLeafNodes(root , ans);
        addRightBoundaryNodes(root , ans);
        
        return ans;
    }
};