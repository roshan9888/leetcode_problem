/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        //brute force memory limit exceded
        // Node* curr=head;
        // queue<Node*>q;
        // while(curr!=NULL){
        //     if(curr->next==NULL){
        //         curr->next=q.front();
        //     }

        //     if(curr->child!=NULL){
        //         q.push(curr->child);
        //     }

        //     curr=curr->next;
        // }
        // return head;

        //optimal solution
        Node* temp;
        Node* curr = head;

        while (curr != NULL) {
        if (curr->child != NULL) {
        Node* tail = curr->child;
        while (tail->next != NULL) {
            tail = tail->next; // Find the last node of the child list
        }
        tail->next = curr->next; // Connect the child list to the main list
        if (curr->next != NULL) {
            curr->next->prev = tail; // Update the previous pointer of the next node if it exists
        }
        curr->next = curr->child; // Connect the current node to the child list
        curr->child->prev = curr; // Update the previous pointer of the child list's head
        curr->child = NULL; // Set child pointer to NULL
    }
    curr = curr->next; // Move to the next node in the main list
}
return head;
    }
};