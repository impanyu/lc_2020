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
//method 1: recursive
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* p = swapPairs(head->next->next);
        ListNode* tmp = head->next;
        head->next = p;
        tmp->next = head;
        return tmp;
    }
};


//method 2: iterative
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1,head);
        ListNode* p = dummy;
        while(p->next && p->next->next){
            ListNode* tmp = p->next->next;
            p->next->next = tmp -> next;
            tmp->next = p->next;
            p->next = tmp;
            p = tmp->next;
        }
        return dummy->next;
    }
};
