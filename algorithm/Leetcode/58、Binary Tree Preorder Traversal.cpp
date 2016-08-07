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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> in;
        if(root)
             in.push(root);

        while(!in.empty())
        {
           TreeNode* tmp = in.top();
           res.push_back(tmp->val);
           in.pop();
           if(tmp->right)
               in.push(tmp->right);
           if(tmp->left)
               in.push(tmp->left);
        }
       return res;
    }
};
