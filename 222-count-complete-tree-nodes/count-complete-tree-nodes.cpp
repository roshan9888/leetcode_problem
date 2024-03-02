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
    void inordertraversal(TreeNode* root,int &count){
        if(root==NULL) return;
        inordertraversal(root->left,count);
        cout<<root->val<<" ";
        count++;
        inordertraversal(root->right,count);
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        if(!root->val) return 1;
        int count=0;
        inordertraversal(root,count);
        return count;
    }
};