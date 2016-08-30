/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct cmp
 {
     bool operator()(ListNode* a, ListNode* b)
     {
            return a->val > b->val;
     }
 };
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>, cmp > heap;
        for(int i=0; i<lists.size(); i++)
        {
              if(lists[i]!=NULL)
              heap.push(lists[i]);
        }
        ListNode* root = new ListNode(-1);
        ListNode* head = root;
        while(!heap.empty())
        {
             ListNode* tmp = heap.top();
             heap.pop();
             head->next = tmp;
             if(tmp->next)
             heap.push(tmp->next);
             head = head->next;
        }
        return root->next;
    }
};
