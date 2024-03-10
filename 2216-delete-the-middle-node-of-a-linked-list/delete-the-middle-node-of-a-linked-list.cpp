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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
            }   
        }
        ListNode* cut=head;
        while(cut->next!=slow){
            cut=cut->next;
        }
        cut->next=cut->next->next;
        return head;
    }
};