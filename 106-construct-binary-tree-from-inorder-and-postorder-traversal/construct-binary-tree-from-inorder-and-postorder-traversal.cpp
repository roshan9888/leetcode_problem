/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* build(vector<int>& postorder, int prestart, int prend,
                    vector<int>& inorder, int instart, int inend,
                    unordered_map<int, int>& mp) {
        if (prestart > prend || instart > inend) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[prend]);
        int inroot = mp[postorder[prend]];
        int numleft = inroot - instart;
        root->left = build(postorder, prestart, prestart + numleft - 1, inorder,
                           instart, inroot - 1, mp);
        root->right = build(postorder, prestart + numleft, prend - 1, inorder,
                            inroot + 1, inend, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        if (inorder.size() != postorder.size())
            return NULL;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return build(postorder, 0, postorder.size() - 1, inorder, 0,
                     inorder.size() - 1, mp);
    }
};