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
ListNode* reverseLinkedlList(ListNode*head){
    if(head==NULL || head->next==NULL) return head;
    ListNode* newHead=reverseLinkedlList(head->next);
    ListNode*front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}
    bool isPalindrome(ListNode* head) {
        //brute force
        // ListNode* temp=head;
        // stack<int>st;
        // while(temp!=NULL){
        //     st.push(temp->val);
        //     temp=temp->next;
        // }

        // temp=head;
        // while(temp!=NULL){
        //     if(temp->val!=st.top()){
        //         return false;   
        //     }
        //     temp=temp->next;
        //     st.pop();
        // }
        // if(st.size()==0) return true;
        // return false;

        //optimal solution
        if(head==NULL || head->next==NULL) return true;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*newHead=reverseLinkedlList(slow->next);
        ListNode*first=head;
        ListNode*second=newHead;
        while(second!=NULL){
            if(first->val !=second->val){
                reverseLinkedlList(newHead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverseLinkedlList(newHead);
        return true;
    }
};