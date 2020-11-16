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
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == nullptr) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* pre = nullptr;
        ListNode* cur = slow;
        ListNode* tmp;
        while(cur){
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        
        
        ListNode* dummy = new ListNode(0);
        ListNode* first = head;
        ListNode* second = pre;
        ListNode* p = dummy;
        
        while(first != slow){
            p->next = first;
            p = p->next;
            first = first->next;
            
            p->next = second;
            p = p->next;
            second = second->next;
        }
        
        return;
    }
};
