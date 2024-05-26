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
    int path(TreeNode*root,int &sum){
        if(root==NULL) return 0;
        int left=path(root->left,sum);
        int right=path(root->right,sum);
        if(left<0){
            left=0;
        }
        if(right<0){
            right=0;
        }
        sum=max(sum,left+right+root->val);

        return (root->val)+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        path(root,sum);
        return sum;
    }
};