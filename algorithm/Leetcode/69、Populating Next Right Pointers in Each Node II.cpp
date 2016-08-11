
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode * cur = root;
        while(cur)
        {
            TreeLinkNode *pre = NULL;
            TreeLinkNode *net = NULL;
            for(; cur; cur= cur->next)
            {
                if(!net)
                net = cur->left? cur->left: cur->right;
                if(cur->left)
                {   if(pre)
                    pre->next = cur->left;
                    pre = cur->left;
                }
                if(cur->right)
                {
                    if(pre)
                    pre->next = cur->right;
                    pre = cur->right;
                }
                
            }
            cur = net;
        }
    }
};
