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
    // bool Isbalanced=true;
    int height(TreeNode*root,bool &isbalanced){
        if(!root) return 0;
        int lh=height(root->left,isbalanced);
        int rh=height(root->right,isbalanced);
        if(isbalanced && abs(lh-rh)>1){
            isbalanced=false;
        }
        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        bool isbalanced=true;
        height(root,isbalanced);
        return isbalanced;
    }
};