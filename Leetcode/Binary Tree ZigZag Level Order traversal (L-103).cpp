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
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>> ans;
            if(root == NULL)
                return ans;
    
            queue<TreeNode*> NodesQueue;
            NodesQueue.push(root);
            bool leftToRight = true;
    
            while(!NodesQueue.empty()){
                vector<int> level;
    
                int size = NodesQueue.size(); //want it to be static even after inserting elements
                for(int i = 0 ; i < size ; i++){
                    TreeNode* node = NodesQueue.front();
                    NodesQueue.pop();
    
                    if(node->left)
                        NodesQueue.push(node->left);
                    if(node->right)
                        NodesQueue.push(node->right);
    
                    level.push_back(node->val);
                }
    
                if(leftToRight == false)
                    reverse(level.begin() , level.end());
    
                ans.push_back(level);
                leftToRight = !leftToRight;
            }
    
            return ans;
        }
    };