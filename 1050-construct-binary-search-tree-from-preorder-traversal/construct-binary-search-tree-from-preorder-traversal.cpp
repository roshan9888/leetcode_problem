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
    TreeNode*build(vector<int>&preorder,int prestart,int prend,vector<int>&inorder,int instart,int inend,unordered_map<int,int>&mp){
        if(prestart>prend || instart>inend){
            return nullptr;
        }
        TreeNode*root=new TreeNode(preorder[prestart]);
        int inroot=mp[root->val];
        int numleft=inroot-instart;
        root->left=build(preorder,prestart+1,prestart+numleft,inorder,instart,inroot-1,mp);
        root->right=build(preorder,prestart+numleft+1,prend,inorder,inroot+1,inend,mp);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        unordered_map<int,int>mp;
        vector<int>inorder=preorder;
        sort(inorder.begin(),inorder.end());
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
    } 
};