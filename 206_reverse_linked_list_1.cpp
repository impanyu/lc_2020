/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//method 1: similar to Problem 24: swap nodes in pairs
//1<-2<-3<-4->5->6
//         |  |
//        pre cur
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
          if(!head || !head->next) return head;
          ListNode* new_head = reverseList(head->next);
          head->next->next = head;
          head->next = nullptr;
          return new_head;
    }
};


//method 2

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur){
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }
}
