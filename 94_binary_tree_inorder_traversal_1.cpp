/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> nodes;
        while(root != nullptr){
            nodes.push(root);
            root = root->left;
        }
        
        while(!nodes.empty()){
            TreeNode* cur = nodes.top();
            nodes.pop();
            ans.push_back(cur->val);
            TreeNode* right = cur -> right;
            while(right != nullptr){
                nodes.push(right);
                right = right->left;
            }   
        }
        return ans;
    }
};
