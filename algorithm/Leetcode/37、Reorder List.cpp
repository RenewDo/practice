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
    void reorderList(ListNode* head) {
      if(!head ||!head->next||!head->next->next) return ;
      ListNode *p1 =head, *p2= head, *right, *left,*p3;
      while(p2 && p2->next)
      {
          p1 = p1->next;
          p2 = p2->next->next;
      }
      right = p2 = p3 = p1->next;
      p1->next = NULL;
      left = head;
      while(p2->next)
      {
          p3 = p2->next;
          p2->next = p3->next;
          p3->next = right;
          right = p3;
      }
      while(left && right)
      {
          p1 = right->next;
          right->next = left->next;
          left->next = right;
          right = p1;
          left = left->next->next;
      }
    }
};
