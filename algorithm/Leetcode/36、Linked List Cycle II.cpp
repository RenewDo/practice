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
    ListNode *detectCycle(ListNode *head) {
        ListNode * p1 = head, *p2 = head, *p3 = head;
        while(p2!=NULL)
        {
            p1 = p1->next;
            if(p2->next==NULL)
              return NULL;
            p2 = p2->next->next;
            if(p1 == p2)
               break;
        }
        if(p2==NULL)
              return NULL;
        while(p1 != p3)
        {
            p1 = p1->next;
            p3 = p3->next;
        }
        return p3;
        
    }
};
