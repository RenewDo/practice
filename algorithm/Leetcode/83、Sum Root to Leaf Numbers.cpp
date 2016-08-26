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
    int sumNumbers(TreeNode* root) {
        if(!root)
           return 0;
           int v = 0;
        return sum(root, root->val, v);
    }
    int sum(TreeNode *r, int cur, int &tot)
    {
        if(!r->left && !r->right)
        {
            tot += cur;
            return tot;
        }
        if(r->left)
           sum(r->left, cur*10+r->left->val, tot);
        if(r->right)
           sum(r->right, cur*10+r->right->val, tot);
        return tot;
    }
};
