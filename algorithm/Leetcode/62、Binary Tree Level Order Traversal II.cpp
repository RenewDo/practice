
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> cur,next;
        if(root)
              cur.push(root);
        else  return res;
        while(!cur.empty())
        {
            vector<int> level;
            while(!cur.empty())
            {
                TreeNode * tmp= cur.front();
                cur.pop();
                level.push_back(tmp->val);
                if(tmp->left)
                next.push(tmp->left);
                if(tmp->right)
                next.push(tmp->right);
            }
            
            res.push_back(level);
            swap(next, cur);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
