/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*>mp;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        if(mp.find(node)!=mp.end()){
            return mp[node];
        }
        Node*clone=new Node(node->val);
        mp[node]=clone;
        for(Node*it:node->neighbors){
            clone->neighbors.push_back(cloneGraph(it));
        }
        return clone;
    }

    // void dfs(Node* node) {
    //     if (visited.count(node)) return;
    //     visited.insert(node);

    //     cout << "Node " << node->val << " neighbors: ";
    //     for (Node* it : node->neighbors) {
    //         cout << it->val << " ";
    //     }
    //     cout << endl;

    //     for (Node* it : node->neighbors) {
    //         dfs(it);
    //     }
    // }
};
