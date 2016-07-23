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
    ListNode* swapPairs(ListNode* head) {
        ListNode list(-1);
        if(!head||!head->next)
            return head;
        list.next = head;
        ListNode *pre = &list, *cur =head, *p2= head->next;
        while(p2)
        {
            cur->next = p2->next;
            p2->next = pre->next;
            pre->next = p2;
            if(!cur->next)
                 return list.next;
            pre = cur;
            cur = cur->next;
            p2= cur->next;
        }
        return list.next;
    }
};
