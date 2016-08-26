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
    ListNode* insertionSortList(ListNode* head) {
            if(!head || !head->next)
                  return head;
            ListNode* root = new ListNode(-1);
            root->next =head;
            head = root;
            ListNode* cur , *min , *minpre,*pre ;
            while(head->next)
            {
                min =cur = head->next;
                minpre = pre = head;
                while(cur)
                {
                    if(cur->val < min->val)
                    {
                        minpre = pre;
                        min = cur;
                    }
                    else
                    {
                        cur = cur->next;
                        pre = pre->next;
                    }
                }
                minpre->next = min->next;
                min->next = head->next;
                head->next = min;
                head = head->next;
            }
            return root->next;
    }
};
