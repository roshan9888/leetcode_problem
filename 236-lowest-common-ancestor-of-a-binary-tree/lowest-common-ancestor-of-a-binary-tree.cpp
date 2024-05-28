/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool traverse(TreeNode*root,TreeNode*p,vector<int>&v1){
       if(!root) return false;
       v1.push_back(root->val);
       if(root->val==p->val){
           return true;
       }
        if(traverse(root->left,p,v1) || traverse(root->right,p,v1)){
            return true;
        }
       v1.pop_back();
       return false;
    }
    vector<int>solve(TreeNode*root,TreeNode*p){
        vector<int>v1;
        if(!root) return v1;
        traverse(root,p,v1);
        return v1;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int>v1;
        vector<int>v2;
        v1=solve(root,p);
        v2=solve(root,q);
        // int ans=0;
        // bool find=false;
        // for(int i=v1.size()-1;i>=0;i--){
        //     for(int j=v2.size();j>=0;j--){
        //         if(v1[i]==v2[i]){
        //             ans=v1[i];
        //             find=true;
        //             break;
        //         }
        //     }
        //     if(find){
        //         break;
        //     }
        // }
        // TreeNode*ans1=new TreeNode(ans);
        // return ans1;

        int i;
        for (i = 0; i < v1.size() && i < v2.size(); ++i) {
            if (v1[i] != v2[i]) break;
        }

        // i-1 will be the index of the last common ancestor in the paths
        return new TreeNode(v1[i-1]);
    }
};