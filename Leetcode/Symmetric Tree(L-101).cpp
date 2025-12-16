/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool checkSymmetry(TreeNode* leftNode, TreeNode* rightNode){
        if(leftNode == NULL && rightNode == NULL)
            return true;

        if(leftNode == NULL || rightNode == NULL)
            return false;

        if(leftNode->val != rightNode->val)
            return false;

        return checkSymmetry(leftNode->left, rightNode->right) && checkSymmetry(leftNode->right, rightNode->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;

        return checkSymmetry(root->left , root->right);
    }
};