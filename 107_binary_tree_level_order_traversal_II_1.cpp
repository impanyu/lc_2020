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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> v;
            while(size > 0){
                TreeNode* cur = q.front();
                q.pop();
                v.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                size--;
            }
            ans.push_back(v);
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};
