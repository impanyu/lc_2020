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
    int ans;
    int sumNumbers(TreeNode* root) {
        sumN(root,0);
        return ans;
    }
    void sumN(TreeNode* root, int sum){
        if(!root) return;
        else if(!root->left && !root->right) 
            ans += sum*10 + root->val;
        else{
            sumN(root->left,sum*10 + root->val);
            sumN(root->right,sum*10+root->val);
        }
    }
};
