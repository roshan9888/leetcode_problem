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
    void Traverse(ListNode* head,vector<int>&vec){
        if(!head) return;

        while(head!=nullptr){
            vec.push_back(head->val);
            head=head->next;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>vec;
        for(auto it:lists){
            Traverse(it,vec);
        }
        priority_queue<int,vector<int>,greater<int>>minHeap;
        for(int i=0;i<vec.size();i++){
           minHeap.push(vec[i]);
        }
        ListNode*newlist=nullptr;;
        ListNode*tail=nullptr;
        while (!minHeap.empty()) {
    ListNode *newnode = new ListNode(minHeap.top());
    minHeap.pop();

    if (newlist == nullptr) {
        newlist = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}
        return newlist;
    }
};