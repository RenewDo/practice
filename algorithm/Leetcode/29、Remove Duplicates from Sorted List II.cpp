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
    ListNode* deleteDuplicates(ListNode* head) {
            ListNode list(-1);
            list.next= head;
            ListNode* h= &list, *pre=h, *curf =pre->next, *cure= pre->next;
            while(cure!=NULL)
            {
                while(cure!=NULL && curf->val == cure->val)
                {
                    cure = cure->next;
                }
                if(cure==NULL)
                {
                    if(curf->next == cure)
                    return list.next;
                    pre->next = NULL;
                    return list.next;
                }
                else if(curf->next != cure)
                {
                    pre->next = cure;
                    curf = cure;
                    continue;
                }
                pre = curf;
                curf = cure;

            }
            return list.next;
    }
};
