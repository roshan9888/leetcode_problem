/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void getLeafNodes(TreeNode* root, std::vector<int>& leafNodes) {
    if (!root) {
        return;
    }

    if (!root->left && !root->right) {
        // If the current node is a leaf node, add its value to the vector
        leafNodes.push_back(root->val);
    }

    // Traverse the left and right subtrees
    getLeafNodes(root->left, leafNodes);
    getLeafNodes(root->right, leafNodes);
}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>num1;
        vector<int>num2;
        getLeafNodes(root1,num1);
        getLeafNodes(root2,num2);
        if(num1.size()!=num2.size()) return false;
        for(int i=0;i<num1.size();i++){
            if(num1[i]!=num2[i]){
                return false;
            }
        }
        return true;
    }
};