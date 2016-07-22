/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode first(-1);
        first.next = head;
        ListNode *pre = &first;
        int i;
        if(m==n) return first.next;
        for( i=0; i<m-1; i++)
           pre = pre->next;
        ListNode *cur = pre->next, *ne = cur->next;
        for(i=m;i<n; i++ )
        {
            cur->next = ne->next;
            ne->next = pre->next;
            pre->next = ne;
            ne = cur->next;
           // cur = pre->next;
        }
        
      /*  ListNode *rev = pre->next->next, *left, *headne;
        for(i=m;i<n; i++ )
        {
            pre->next->next = rev->next;
            headne = pre->next;
            pre->next = rev; 
           // left = rev->next;
            rev->next = headne;
            if(headne->next)
            rev = headne->next;
        }*/
        return first.next;
    }
};
