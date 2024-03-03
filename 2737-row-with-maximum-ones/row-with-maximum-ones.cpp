class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        // unordered_map<int,int>mp;
        vector<int>ans;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    count++;
                }
            }
            ans.push_back(count);
        }
        vector<int>ans1;
        // for(auto it:ans){
        //     cout<<it<<" ";
        // }
        int maxElement=INT_MIN;
        int maxIndex=-1;
        for (int i = 0; i < ans.size(); ++i) {
        if (ans[i] > maxElement) {
            maxElement = ans[i];
            maxIndex = i;
        }
    }
    ans1.push_back(maxIndex);
    ans1.push_back(maxElement);
        return ans1;
    }
};