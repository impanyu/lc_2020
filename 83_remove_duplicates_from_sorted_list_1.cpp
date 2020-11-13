/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//two pointers, starting from the same place
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr) return head;
        ListNode* i=head;
        ListNode* j=head;
        while(j!=nullptr){
            if(j->val!=i->val){
                i->next=j;
                i=i->next;
            }
            else
               j=j->next;
        }
        i->next=nullptr;
        return head;
    }
};
