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
    int minDepth(TreeNode* root) {
        // if(!root) return 0;
        // if(!root->left) return minDepth(root->right)+1;
        // if(!root->right) return minDepth(root->left)+1;

        // return min(minDepth(root->left),minDepth(root->right))+1;

         if (!root) {
            return 0;  // Return 0 for null nodes
        }

        // If both left and right child nodes are null, return 1
        if (!root->left && !root->right) {
            return 1;
        }

        int leftDepth = INT_MAX;
        int rightDepth = INT_MAX;

        // Calculate the depth of the left subtree
        if (root->left) {
            leftDepth = minDepth(root->left);
        }

        // Calculate the depth of the right subtree
        if (root->right) {
            rightDepth = minDepth(root->right);
        }

        // Return the minimum depth of the left and right subtrees + 1
        return min(leftDepth, rightDepth) + 1;
    }
};