//https://www.naukri.com/code360/problems/tree-traversal_981269
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void inorderTraversal(TreeNode *root , vector<int> &arr){
    if(root != NULL){
        inorderTraversal(root->left , arr);
        arr.push_back(root->data);
        inorderTraversal(root->right , arr);
    }
}

void preorderTraversal(TreeNode *root , vector<int> &arr){
    if(root != NULL){
        arr.push_back(root->data);
        preorderTraversal(root->left , arr);
        preorderTraversal(root->right , arr);
    }
}

void postorderTraversal(TreeNode *root , vector<int> &arr){
    if(root != NULL){
        postorderTraversal(root->left , arr);
        postorderTraversal(root->right , arr);
        arr.push_back(root->data);
    }
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<int> inorder;
    inorderTraversal(root , inorder);

    vector<int> preorder;
    preorderTraversal(root , preorder);

    vector<int> postorder;
    postorderTraversal(root , postorder);

    vector<vector<int>> ans;
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
    return ans;

}