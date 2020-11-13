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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy -> next = head;
        ListNode* first = dummy;
        ListNode* second = dummy->next;
        int count =0;
        while(second){
          if(first->next->val == second->val){
              second = second->next;  
              count++;
          }
          else{
              if(count>=2)
                  first->next = second;
              else
                  first = first->next;
              count = 0;
          }
        }
        if(count>=2)  first->next = second;
        return dummy->next;
        
    }
};
