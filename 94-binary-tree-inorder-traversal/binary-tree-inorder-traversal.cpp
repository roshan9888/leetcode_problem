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
    // void inorder(TreeNode*root,vector<int>&ans){
    //     if(root==NULL) return;
    //     inorder(root->left,ans);
    //     ans.push_back(root->val);
    //     inorder(root->right,ans);
    // }

    // void MorrisTraversalInorder(TreeNode*root,vector<int>&inorder){
    //     TreeNode*cur=root;
    //     while(cur!=NULL){
    //         if(cur->left==NULL){
    //             inorder.push_back(cur->val);
    //             cur=cur->right;
    //         }
    //         else{
    //            TreeNode*prev=cur->left;
    //            while(prev->right && prev->right!=cur){
    //               prev=prev->right;
    //            }

    //            if(prev->right==NULL){
    //               prev->right=cur;
    //               cur=cur->left;
    //            }
    //            else{
    //             prev->right=NULL;
    //             inorder.push_back(cur->val);
    //             cur=cur->right;
    //            }
    //         }
    //     }
    // }

    void MorrisTraversalPreorder(TreeNode*root,vector<int>&Preorder){
        TreeNode*cur=root;
        while(cur!=NULL){
            if(cur->left==NULL){
                Preorder.push_back(cur->val);
                cur=cur->right;
            }
            else{
               TreeNode*prev=cur->left;
               while(prev->right && prev->right!=cur){
                  prev=prev->right;
               }
               if(prev->right==cur){
                prev->right=NULL;
                Preorder.push_back(cur->val);
                cur=cur->right;
               }
               else{
                prev->right=cur;
                cur=cur->left;
               }
            }
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int>ans;
        // inorder(root,ans);
        // return ans;

        // vector<int>inorder;
        // MorrisTraversalInorder(root,inorder);
        // return inorder;

        vector<int>Preorder;
        MorrisTraversalPreorder(root,Preorder);
        return Preorder;
    }
};