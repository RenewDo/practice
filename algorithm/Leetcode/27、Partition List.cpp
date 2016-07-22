
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
    ListNode* partition(ListNode* head, int x) {
        ListNode list(-1);
        list.next = head;
        ListNode* pre =&list, *cur = pre->next;
        while(cur!=NULL && cur->val <x)
        {
            pre = cur;
            cur = cur->next;
        }
        ListNode *h= pre;
        while(cur!=NULL)
        {
            while(cur!=NULL && cur->val>=x)
            {
                pre = cur;
                cur = cur->next;
            }
            if(cur == NULL) 
               return list.next;
            pre->next = cur->next;
            cur->next = h->next;
            h->next = cur;
            cur = pre->next;
            h = h->next;
        }
        return list.next;
    }
};
