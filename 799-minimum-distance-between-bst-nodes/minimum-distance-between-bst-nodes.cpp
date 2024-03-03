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
    void inordertraversal(TreeNode* root,vector<int>&v){
        if(!root) return;
        inordertraversal(root->left,v);
        v.push_back(root->val);
        inordertraversal(root->right,v);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int>v;
        inordertraversal(root,v);
        int mini=INT_MAX;
        for(int i=0;i<v.size()-1;i++){
            int diff=abs(v[i]-v[i+1]);
            mini=min(mini,diff);
        }
        return mini;
    }
};