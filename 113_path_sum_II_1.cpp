/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//back tracking
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> out;
        dfs(root,sum,out);
        return ans;
    }
    void dfs(TreeNode* root, int sum, vector<int>& out){
        if(!root) return;
        out.push_back(root->val);
        if(sum==root->val && !root->left && !root->right){
            ans.push_back(out);
        }
        else{         
          dfs(root->left,sum-root->val,out);
          dfs(root->right,sum-root->val,out);
        }
        out.pop_back();
    }
};
