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
        vector<int> res;
        stack<TreeNode*> in;
        TreeNode* p = root;
        while(p || !in.empty())
        {
            if(p)
            {
                in.push(p);
                p= p->left;
            }
            else
            {
                TreeNode* tmp = in.top();
                in.pop();
                res.push_back(tmp->val);
                p = tmp->right;
            }
        }
        return res;
    }
};
