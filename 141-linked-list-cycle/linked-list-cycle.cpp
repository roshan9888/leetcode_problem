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
    bool hasCycle(ListNode *head) {
        //brute force
        // unordered_set<ListNode*>visited;
        // ListNode*curr=head;
        // while(curr!=NULL){
        //     if(visited.find(curr)!=visited.end()){
        //         return true;
        //     }

        //     visited.insert(curr);
        //     curr=curr->next;
        // }
        // return false;

        //optimal 

        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};