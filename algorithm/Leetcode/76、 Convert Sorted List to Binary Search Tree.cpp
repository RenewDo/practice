/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        int len =0;
        ListNode *p =head;
        while(p)
        {
            len++;
            p= p->next;
        }
        return sort(head, 0, len-1);
    }
    TreeNode* sort(ListNode*& head, int l, int h)
    {
         if(l>h) return NULL;
         int mid = l+(h-l)/2;
         TreeNode* leftC = sort(head, l, mid-1);
         TreeNode *r = new TreeNode(head->val);
         r->left = leftC;
         head = head->next;
         r->right = sort(head, mid+1, h);
         return r;
    }
};
