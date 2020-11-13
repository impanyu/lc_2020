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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        if(!p1 || !p2) return nullptr;
        while(p1 != p2){
            p1 = p1? p1->next : headB;
            p2 = p2? p2->next : headA;
        }
        return p1;
    }
};
