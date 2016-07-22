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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode add(-1);
        ListNode *list = &add;
        int carry;
        ListNode *pa = l1, *pb = l2;
        for(; pa!=NULL || pb!=NULL; pa = pa==NULL?NULL:pa->next, pb= pb==NULL?NULL:pb->next,list = list->next)
        {
            int a = pa== NULL? 0 :pa->val;
            int b = pb==NULL? 0 : pb->val;
            int val = (a+b+carry)%10;
            carry = (a+b+carry)/10;
            list->next = new ListNode(val);
        }
        if(carry>0)
           list->next = new ListNode(carry);
        return add.next;
    }
};
