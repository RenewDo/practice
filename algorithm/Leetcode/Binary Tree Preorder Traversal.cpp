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
               if(root == NULL)
                      return res;
               stack<TreeNode*> node;
               node.push(root);
               TreeNode *p, *cur;
               p = root;
               res.push_back(p->val);
               while(!node.empty())
               {
                      while(p->left != NULL)
                      {
                            p = p->left;
                            res.push_back(p->val);
                            node.push(p);
                      }
                      cur = node.top();
                      node.pop();
                      if(cur->right != NULL)
                      {
                            p = cur->right;
                            res.push_back(p->val);
                            node.push(p);
                      }
               }
               return res;
    }
};
