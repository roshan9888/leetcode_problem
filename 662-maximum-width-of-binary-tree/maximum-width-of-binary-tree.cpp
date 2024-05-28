// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     int widthOfBinaryTree(TreeNode* root) {
//         if(!root) return 0;
//         int ans=0;
//         queue<pair<TreeNode*,int>>q;
//         q.push({root,0});
//         while(!q.empty()){
//            int mmin = q.front().second;
//            int first,last;
//            int size=q.size();
//            for(int i=0;i<size;i++){
//               int curr_i=q.front().second-mmin;
//               TreeNode* node=q.front().first;
//               q.pop();

//               if(i==0){
//                 first=curr_i;
//               }

//               if(i==size-1){
//                 last=curr_i;
//               }

//               if(node->left){
//                 q.push({node->left,curr_i*2+1});
//               }

//               if(node->right){
//                 q.push({node->right,curr_i*2+2});
//               }
//            }
//            ans=max(ans,last-first+1);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        queue<pair<TreeNode*, unsigned long long>> q; // Use unsigned long long for large indices
        q.push({root, 0});
        
        while (!q.empty()) {
            int size = q.size();
            unsigned long long mmin = q.front().second; // To prevent overflow
            unsigned long long first, last;
            
            for (int i = 0; i < size; ++i) {
                unsigned long long curr_i = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();
                
                if (i == 0) {
                    first = curr_i;
                }
                
                if (i == size - 1) {
                    last = curr_i;
                }
                
                if (node->left) {
                    q.push({node->left, 2 * curr_i + 1});
                }
                
                if (node->right) {
                    q.push({node->right, 2 * curr_i + 2});
                }
            }
            ans = max(ans, static_cast<int>(last - first + 1));
        }
        
        return ans;
    }
};