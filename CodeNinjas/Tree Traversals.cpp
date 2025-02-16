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
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<vector<int>> ans;
    stack<pair<TreeNode*, int>> st;
    st.push({root , 1});
    vector<int> pre, post, inorder;

    if(root == NULL) return ans;

    while(!st.empty()){
        auto it = st.top();
        st.pop();

        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left != NULL)
                st.push({it.first->left , 1});
        }

        else if(it.second == 2){
            inorder.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right != NULL)
                st.push({it.first->right , 1});
        }

        else{
            post.push_back(it.first->val);
        }
    }
    ans.push_back(inorder);
    ans.push_back(pre);
    ans.push_back(post);

    return ans;
}