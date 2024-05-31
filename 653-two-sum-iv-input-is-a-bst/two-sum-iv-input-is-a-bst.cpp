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
class BSTIterator {
    stack<TreeNode*>st;
    bool reverse=true;
public:
    BSTIterator(TreeNode* root,bool isreverse) {
       reverse=isreverse;
       pushAll(root); 
    }

    void pushAll(TreeNode*root){
        for( ;root!=NULL;){
            st.push(root);
            if(reverse==true){
                root=root->right;
            }
            else{
                root=root->left;
            }
    }
    }

    int next() {
        TreeNode*tmp=st.top();
        st.pop();
        if(!reverse) pushAll(tmp->right);
        else{
            pushAll(tmp->left);
        }
        pushAll(tmp->right);
        return tmp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);

        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k){
                i=l.next();
            }
            else{
                j=r.next();
            }
        }
        return false;
    }
};