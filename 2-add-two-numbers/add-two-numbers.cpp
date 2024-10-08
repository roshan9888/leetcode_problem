
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
    ListNode*reverse(ListNode*head){
        if(head==NULL || head->next==NULL) return head;
        ListNode*newhead=reverse(head->next);
        ListNode*front=head->next;
        front->next=head;
        head->next=NULL;
        return newhead;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*newhead=new ListNode();
        ListNode*temp=newhead;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry){
           int sum=0;

           if(l1!=NULL){
            sum+=l1->val;
            l1=l1->next;
           }

           if(l2!=NULL){
            sum+=l2->val;
            l2=l2->next;
           }

           sum+=carry;
           carry=sum/10;
           ListNode*node=new ListNode(sum%10);
           temp->next=node;
           temp=temp->next;
        }
        return newhead->next;
    }
};