
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
    void flatten(TreeNode* root) {
        if(!root)
           return ;
        stack<TreeNode* > in;
        in.push(root);
        while(!in.empty())
        {
            TreeNode* tmp = in.top();
            in.pop();
            if(tmp->right)
            in.push(tmp->right);
            if(tmp->left)
            in.push(tmp->left);
            tmp->left = NULL;
            if(!in.empty())
            tmp->right = in.top();
            else tmp->right = NULL;
        }
    }
};
