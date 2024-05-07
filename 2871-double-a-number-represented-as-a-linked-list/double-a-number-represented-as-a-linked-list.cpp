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
    ListNode* reverse(ListNode* head) {
    if(!head || !head->next) {
        return head;
    }
    
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;
    
    while(current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
    ListNode* doubleIt(ListNode* head) {
        ListNode* newhead=reverse(head);
        ListNode* temp=newhead,*prev=nullptr;
        int carry=0;
        while(temp!=nullptr){
            int newvalue=temp->val*2+carry;
            temp->val=newvalue%10;
            if(newvalue>9){
                carry=1;
            }else{
                carry=0;
            }
            prev=temp;
            temp=temp->next;
        }

        if(carry!=0){
            ListNode* extranode=new ListNode(carry);
            prev->next=extranode;
        }

        ListNode*result=reverse(newhead);
        return result;
    }
};