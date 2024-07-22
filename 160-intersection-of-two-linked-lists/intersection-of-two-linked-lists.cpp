/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return headA;
        ListNode*first=headA;
        ListNode*second=headB;
        while(first!=second){
            first=first->next;
            second=second->next;
            if(first==second) return first;
            if(!first) first=headB;
            if(!second) second=headA; 
        }
        return first;
    }
};