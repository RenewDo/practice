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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> cur,next;
        int i=1;
        if(root)
             cur.push(root);
        else return res;
        while(!cur.empty())
        {
             vector<int> lev;
             while(!cur.empty())
             {
                 TreeNode * tmp = cur.front();
                 cur.pop();
                 if(tmp->left)
                     next.push(tmp->left);
                 if(tmp->right)
                     next.push(tmp->right);
                 lev.push_back(tmp->val);
             }
             if(i%2==0)
             reverse(lev.begin(), lev.end());
             res.push_back(lev);
             i++;
             swap(cur,next);
        }
        return res;
    }
};
