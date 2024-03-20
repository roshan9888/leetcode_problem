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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp1=list1;
        ListNode* temp2=list1;
        int len1=0;
        int len2=0;
        while(len1!=a-1){
            len1++;
            temp1=temp1->next;
        }
         while(len2!=b){
            len2++;
            temp2=temp2->next;
        }

        cout<<temp1->val<<" ";
        cout<<temp2->val<<" ";
        temp1->next=list2;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        cout<<temp1->val<<" ";

        temp1->next=temp2->next;
        temp2->next=NULL;
        return list1;
    }
};