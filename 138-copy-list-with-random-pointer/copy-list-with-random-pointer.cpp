/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    // Node* solve(Node* head,unordered_map<Node*,Node*>&mp){
    //     if(head==NULL) return head;
    //     Node*newHead=new Node(head->val);
    //     mp[head]=newHead;
    //     newHead->next=solve(head->next,mp);
    //     if(head->random){
    //         newHead->random=mp[head->random];
    //     }
    //     return newHead;
    // }

    Node* copyRandomList(Node* head) {
        // unordered_map<Node*,Node*>mp;
        // return solve(head,mp);


        if(!head) return 0;
        Node* it=head;
        while(it){
            Node*clonednode=new Node(it->val);
            clonednode->next=it->next;
            it->next=clonednode;
            it=it->next->next;
        }
        it=head;
        while(it){
            Node*clonednode=it->next;
            clonednode->random=it->random ? it->random->next : nullptr;
            it=it->next->next;
        }
        it=head;
        Node*clonehead=it->next;
        while(it){
           Node*clonenode=it->next;
           it->next=it->next->next;
           if(clonenode->next){
               clonenode->next=clonenode->next->next;
           }
           it=it->next;
        }
        return clonehead;
    }
};