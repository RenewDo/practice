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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0||head==NULL)
            return head;
        ListNode *pre = head;
        int i=1;
        while(pre->next)
        {
            pre = pre->next;
            i++;
        }
        k =i- k%i;
        pre->next = head;
        ListNode *res ;
        while(k--)
        pre = pre->next;
        res = pre->next;
        pre->next = NULL;
        return res;
    }
};
