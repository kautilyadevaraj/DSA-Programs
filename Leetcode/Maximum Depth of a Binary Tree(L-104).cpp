class Solution {
    private:
    int recursion(TreeNode* root){
        if (root == NULL)
            return 0;
        return 1 + max(recursion(root->left) , recursion(root->right));
    }
public:
    int maxDepth(TreeNode* root) {
        return recursion(root);
    }
};