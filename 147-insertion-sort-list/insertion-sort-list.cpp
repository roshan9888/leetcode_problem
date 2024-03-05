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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL && head->next==NULL) return head;

        ListNode* preInsert;
        ListNode* toInsert;
        ListNode *dummyHead=new ListNode(INT_MIN);
        dummyHead->next=head;
        ListNode* curr=head;
        while(curr!=NULL && curr->next!=NULL){
            if(curr->val<=curr->next->val){
                curr=curr->next;
            }
            else{
               toInsert=curr->next;
               preInsert=dummyHead;
               while(preInsert->next->val<toInsert->val){
                   preInsert=preInsert->next;
               }
               curr->next=toInsert->next;
               toInsert->next=preInsert->next;
               preInsert->next=toInsert;
            }
        }
        return dummyHead->next;
    }
};