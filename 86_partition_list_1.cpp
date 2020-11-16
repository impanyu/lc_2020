/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//two pointers: one read and one write
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* p1 = dummy;
        ListNode* p2 = dummy;
        
        while(p2->next){
            if(p2->next->val < x){
                ListNode* tmp = p2 ->next;
                p2->next = tmp->next;
                tmp->next = p1->next;
                p1->next = tmp;
                if(p1 == p2)
                    p2 = p2 ->next;
                p1 = p1->next;
            }
            else
                p2 = p2->next;
        }
        return dummy->next;
    }
};
