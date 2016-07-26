
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
           return head;
        RandomListNode *pre = head;
        while(pre!=NULL)
        {
             RandomListNode *tmp= new RandomListNode(pre->label);
             tmp->next = pre->next;
             pre->next = tmp;
             pre= tmp->next;
        }
        pre = head;
        while(pre!=NULL)
        {
            if(pre->random)
            pre->next->random = pre->random->next;
            pre = pre->next->next;
        }
        pre = head;
        RandomListNode newlist(-1);
        RandomListNode *cur = &newlist;
        while(pre!=NULL)
        {
            cur->next = pre->next;
            cur = cur->next;
            pre->next = pre->next->next;
            pre = pre->next;
        }
        return newlist.next;
    }
};
