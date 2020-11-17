/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//two pointers
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        while(p1 && p2){
            if( p1->val <= p2->val)  {
                p->next=p1;
                p1 = p1->next;
            }
            else {
                p->next=p2;
                p2 = p2->next;
            }
            p = p->next;
        }  
        p->next = p1? p1: p2;
        return dummy->next;
    }
};