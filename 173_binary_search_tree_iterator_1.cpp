/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> nodes;
    BSTIterator(TreeNode* root) {
        while(root!=nullptr){
            nodes.push(root);
            root=root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* current;
        current=nodes.top();
        nodes.pop();
        TreeNode* right_child=current->right;
        while(right_child != nullptr){
            nodes.push(right_child);
            right_child=right_child->left;
        }    
        return current->val;   
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nodes.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
