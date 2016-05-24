/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
          vector<int> res;
          if(root == NULL)
                return res;
          stack<TreeNode*> node;
          node.push(root);
          TreeNode* pre, *cur;
          pre = root;
          while(!node.empty())
          {
               cur = node.top();
               if(cur->left == pre || cur->right == pre || (cur->left == NULL && cur->right == NULL))
               {
                    res.push_back(cur->val);
                    node.pop();
                    pre = cur;
               }
               else
               {
                   if(cur->right != NULL)
                            node.push(cur->right);
                   
                   if(cur->left != NULL)
                           node.push(cur->left);
               }
          }
          return res;
    }
};
