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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
        while(n>=0){
            first = first ->next;
            n--;
        }
        
        while(first){
            first = first->next;
            second = second ->next;
        }
        
        second->next = second->next->next;
        return dummy->next;
    }
};
