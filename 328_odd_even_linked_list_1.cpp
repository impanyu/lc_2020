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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* first = head;
        if(first==nullptr) return nullptr;
        ListNode* second = first->next;
        if(second==nullptr) return first;
        
        ListNode* p1 = first;
        ListNode* p2 = second;
        while(p1->next && p2->next){
            p1->next = p2->next;
            p1 = p1->next;
            p2->next = p1->next;
            p2 = p2->next;
        }
        p1->next=second;
        return first;
    }
};
