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
    // ListNode* reverse(ListNode*head){
    //     if(head==NULL || head->next==NULL){
    //         return head;
    //     }
    //     ListNode*newHead=reverse(head->next);
    //     ListNode*front=head->next;
    //     front->next=head;
    //     head->next=NULL;
    //     return newHead;
    // }

    ListNode*reverse(ListNode*head){
        if(!head || !head->next) return head;
        ListNode*curr=head;
        ListNode*prev=NULL;
        while(curr!=NULL){
            ListNode*front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        //brute force
        // ListNode*temp=head;
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
        //     else{
        //         st.pop();
        //         temp=temp->next;
        //     }
        // }
        // return true;

        //optimal solution 
        if(head==NULL || head->next==NULL) return true;
        ListNode*slow=head;
        ListNode*fast=head;
        // while(fast!=NULL){
        //     fast=fast->next;
        //     if(fast!=NULL){
        //         slow=slow->next;
        //         fast=fast->next;
        //     }
        // }

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode*newnode=reverse(slow->next);
        ListNode*first=head;
        ListNode*second=newnode;
        while(second!=NULL){
            if(first->val!=second->val){
                reverse(newnode);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverse(newnode);
        return true;
    }
};