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
    ListNode* sortList(ListNode* head) {
             if(!head || !head->next)
                     return head;
            ListNode* low = head, *fast = head;
            while(fast->next && fast->next->next)
            {
                low = low->next;
                fast = fast->next->next;
            }
            fast = low->next;
            low->next = NULL;
            ListNode * l=sortList(head);
             ListNode * r = sortList(fast);
            return Merge(l, r);
    }
          ListNode* Merge(ListNode*l, ListNode *r)
          {
              ListNode root(-1);
              ListNode* head;
              for( head = &root; l && r; head = head->next)
              {
                  if(l->val <r->val)
                  {
                      head->next = l;
                      l = l->next;
                  }
                  else
                  {
                      head->next = r;
                      r = r->next;
                  }
              }
              if(l)
              head->next = l;
              else if(r) head->next =r;
              return root.next;
          }
};
