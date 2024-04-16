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
    void dfs(TreeNode* node,int val,int depth,int curdepth)
{
    if(node==nullptr) return;

    if(curdepth<depth-1){
        dfs(node->left,val,depth,curdepth+1);
        dfs(node->right,val,depth,curdepth+1);
    }

    if(curdepth==depth-1){
        TreeNode* exLeftChild=node->left;
        TreeNode* exRightChild=node->right;
        TreeNode* newLeftchild=new TreeNode(val);
        TreeNode* newRightchild=new TreeNode(val);
        node->left=newLeftchild;
        newLeftchild->left=exLeftChild;

        node->right=newRightchild;
        newRightchild->right=exRightChild;
    }
}   

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode*curnode=root;
            TreeNode* newnode=new TreeNode(val);
            newnode->left=curnode;
            return newnode;
        }        
        dfs(root,val,depth,1);
        return root;
    }
};