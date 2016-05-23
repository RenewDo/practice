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
               if(root == NULL)
                        return res;
               stack<TreeNode *> node;
               node.push(root);
               TreeNode *p,*cur;
               if(root->left != NULL)
                        p = root->left;
               else
               {
                        res.push_back(root->val);
                        if(root->right != NULL)
                                 p = root->right;
                        else return res;
               }
               while(!node.empty())
               {
                        while(p->left != NULL)
                        {
                              p = p->left;
                              node.push(p);
                        }
                        cur = node.top();
                        node.pop();
                        res.push_back(cur->val);
                        if(cur->right != NULL)
                        {
                              p = cur->right;
                              node.push(p);
                        }
               }
               return res;
    }
};
