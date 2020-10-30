/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//helper has two tasks, first to update res, second to return maximum branch
class Solution {
public:
    int res=INT_MIN;
    int maxPathSum(TreeNode* root) {
        helper(root);
        return res;
    }
    
    int helper(TreeNode* root){
        if(root==nullptr) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        res = max(res, left+right+root->val);
        return max(max(left,right)+root->val,0);
    }
};
