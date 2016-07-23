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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!n||!head)
             return head;
        ListNode list(-1);
        list.next = head;
        ListNode * p1=&list, *p2=&list;
        int k= n;
        while(k--&&p1)
        {
            p1 = p1 ->next;
        }
        if(!p1)
            return list.next;
        while(p1->next)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = p2->next->next;
        return list.next;
    }
};
