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
    void DFS(TreeNode* root, int row , int col, map<int , vector<pair<int,int>>>& mp){
        if(root == NULL) return;

        mp[col].push_back({row , root->val});
        DFS(root->left , row + 1 , col - 1 , mp);
        DFS(root->right , row + 1 , col + 1 , mp);
    }
    static bool cmp(pair<int,int>& ele1 , pair<int,int>& ele2){
        if(ele1.first == ele2.first)
            return ele1.second < ele2.second;
        else
            return ele1.first < ele2.first;
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int , vector<pair<int,int>>> mp;
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        DFS(root , 0 , 0 , mp);

        for(auto&[col , arr] : mp){
            sort(arr.begin() , arr.end() , cmp);

            vector<int> element;

            for(int i = 0 ; i < arr.size() ; i++){
                element.push_back(arr[i].second);
            }

            ans.push_back(element);
        }

        return ans;
    }
};