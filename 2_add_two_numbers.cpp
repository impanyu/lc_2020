/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
//add a dummy head into the list, which plays as a anchor
//creat node one by one and add into the linkedlist, until both l1 and l2 reach end and carry is 0
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int carry =0;
      ListNode* dummy = new ListNode(0);
      ListNode* p = dummy;
      while(l1 || l2 || carry){
          if(l1){
              carry += l1->val;
              l1 = l1->next;
          }
          if(l2){
              carry += l2->val;
              l2 = l2->next;
          }
          p->next = new ListNode(carry%10);
          carry /=10;
          p = p->next;
          
      }
        return dummy->next;
      
        
    }
};
