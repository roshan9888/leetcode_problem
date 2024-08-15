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
    ListNode *detectCycle(ListNode *head) {
        //optimal solution
        // ListNode* slow=head;
        // ListNode* fast=head;
        // while(fast!=NULL && fast->next!=NULL){
        //     slow=slow->next;
        //     fast=fast->next->next;
        //     if(slow==fast){
        //         slow=head;
        //         while(slow!=fast){
        //             slow=slow->next;
        //             fast=fast->next;
        //         }
        //         return slow;
        //     }
        // }
        // return NULL;

        //brute force
        unordered_set<ListNode*>visited;
        ListNode*curr=head;
        while(curr!=NULL){
            if(visited.find(curr)!=visited.end()){
                return curr;
            }

            visited.insert(curr);
            curr=curr->next;
        }
        return NULL;
    }
};