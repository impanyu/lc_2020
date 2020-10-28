/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//reverse of preorder traversal by inserting at the begining
//topology sort is reverse of postorder traversal by using a stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        if(root) st.push(root);
        while(!st.empty()){
            TreeNode* p = st.top();
            st.pop();
            ans.insert(ans.begin(),p->val);   
            //left and right order is reversed, compared with preorder traversal
            if(p->left) st.push(p->left);
            if(p->right) st.push(p->right);
        }
        return ans;
    }
};
