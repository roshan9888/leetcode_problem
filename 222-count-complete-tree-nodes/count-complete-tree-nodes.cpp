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
    int findleftheight(TreeNode*root){
        int height=0;
        while(root){
           height++;
           root=root->left;
        }
        return height;
    }

    int findrightheight(TreeNode*root){
        int height=0;
        while(root){
            height++;
            root=root->right;
        }
        return height;
    }

    int countnodes(TreeNode*root){
        if(root==NULL) return 0;
        int lh=findleftheight(root);
        int rh=findrightheight(root);
        if(lh==rh){
            return (1<<lh)-1;
        }
        
        return 1+countnodes(root->left) +countnodes(root->right);
    }

    int countNodes(TreeNode* root) {
        return countnodes(root);
    }
};