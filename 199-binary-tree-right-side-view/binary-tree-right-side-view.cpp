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
    void rightview(TreeNode*root,int level,vector<int>&q){
        if(root==NULL) return;
        if(level==q.size()) q.push_back(root->val);
        rightview(root->right,level+1,q);
        rightview(root->left,level+1,q);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>q;
        rightview(root,0,q);
        return q;
    }
};