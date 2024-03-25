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
    int prev = INT_MIN, count = 0, max_count = 0;
    vector<int> res;
    void go(TreeNode* root) {
        if (!root) return;
        go(root->left);
        count = prev == root->val ? count + 1 : 1;
        if (count > max_count) res = {}, res.push_back(root->val), max_count = count;
        else if (count == max_count) res.push_back(root->val);
        prev = root->val;
        go(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        go(root);
        return res;
    }
};