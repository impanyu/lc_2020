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
    bool isBalanced(TreeNode* root) {
        return db(root).second;
    }
    
    pair<int,bool> db(TreeNode* root){
        if(root==nullptr) return make_pair(0,true);
        pair<int,bool> left=db(root->left);
        pair<int,bool> right=db(root->right);
        int depth=max(left.first,right.first);
        if(left.second && right.second && abs(left.first-right.first)<=1 ) 
            return make_pair(depth+1,true);
        else 
            return make_pair(depth+1,false);
    }
};
