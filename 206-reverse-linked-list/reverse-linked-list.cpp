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
    ListNode* reverseList(ListNode* head) {
        //recurive
        if(!head || !head->next) return head;
        ListNode*newhead=reverseList(head->next);
        ListNode*front=head->next;
        front->next=head;
        head->next=NULL;
        return newhead;


        // ListNode*prev=NULL;
        // ListNode*curr=head;
        // while(curr!=NULL){
        //     ListNode*front=curr->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=front;
        // }
        // return prev;
    }
};