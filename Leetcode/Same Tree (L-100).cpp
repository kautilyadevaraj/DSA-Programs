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
    bool checkIsSame(TreeNode* p , TreeNode* q){
        if(p == NULL && q == NULL)
            return true;
        if(p == NULL && q)
            return false;
        if(q == NULL && p)
            return false;
        if(p->val != q->val)
            return false;

        return checkIsSame(p->left , q->left) && checkIsSame(p->right , q->right);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return checkIsSame(p , q);
    }
};