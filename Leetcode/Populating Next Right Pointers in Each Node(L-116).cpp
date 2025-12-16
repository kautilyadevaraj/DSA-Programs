/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    void DFS(Node* root){
        if(root == NULL) return;

        if(root->left && root->right){
            root->left->next = root->right;
            root->right->next = root->next ? root->next->left : NULL;
        }

        DFS(root->left);
        DFS(root->right);
    }
public:
    Node* connect(Node* root) {
        //O(n) space solution
        // if(root == NULL) return NULL;

        // queue<Node*> q;
        // q.push(root);

        // while(!q.empty()){
        //     int size = q.size();

        //     for(int i = 0 ; i < size ; i++){
        //         Node* node = q.front();
        //         q.pop();
        //         if(i + 1 < size)
        //             node->next = q.front();
        //         else
        //             node->next = NULL;

        //         if(node->left) q.push(node->left);
        //         if(node->right) q.push(node->right);
        //     }
        // }

        // return root;

        //O(1) space solution
        DFS(root);

        return root;
    }
};