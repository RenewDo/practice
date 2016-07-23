
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head||k<2||!head->next)
        return head;
        ListNode *nextk = head;
        for(int i=0; i<k;i++)
           if(nextk)
              nextk = nextk->next;
          else return head;
       ListNode *new_nextk = reverseKGroup(nextk, k);
       ListNode *pre = NULL, *cur = head;
       while(cur!=nextk)
       {
           ListNode*next = cur->next;
           cur->next = pre? pre: new_nextk;
           pre = cur;
           cur = next;
       }
       return pre;
    }
};
