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
    int maxi = INT_MIN;
    int findMaxPath(TreeNode* root){
        if(root == NULL)
            return 0;

        int lh = max(0 , findMaxPath(root->left));
        int rh = max(0 , findMaxPath(root->right));

        maxi = max(maxi , lh + rh + root->val);

        return root->val + max(lh , rh);
    }
public:
    int maxPathSum(TreeNode* root) {
        findMaxPath(root);

        return maxi;
    }
};