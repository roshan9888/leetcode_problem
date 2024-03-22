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
        if(!head || !head->next) return head;
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* newnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=newnode;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode*L1=reverseList(l1);
       ListNode*L2=reverseList(l2);
       ListNode* dummyhead=new ListNode(0);
       ListNode* tail=dummyhead;
       int carry=0;
       while(L1!=nullptr || L2!=nullptr || carry!=0){
           int digit1=(L1!=nullptr) ? L1->val : 0;
           int digit2=(L2!=nullptr) ? L2->val : 0;
           
           int sum=digit1+digit2+carry;
           int digit=sum%10;
           carry=sum/10;

           ListNode* newNode=new ListNode(digit);
           tail->next=newNode;
           tail=tail->next;

           L1=(L1!=nullptr) ? L1->next : nullptr;
           L2=(L2!=nullptr) ? L2->next : nullptr;
       } 
       ListNode* result=dummyhead->next;
       delete dummyhead;
       return reverseList(result);
    }
};