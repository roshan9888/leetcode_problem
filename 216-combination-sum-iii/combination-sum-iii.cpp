class Solution {
public:
    void combination(vector<int>&candidates,int target,vector<vector<int>>&ans,vector<int>&v,int index,int k){
        if(target==0){
            if(v.size()==k){
       ans.push_back(v);

            }
        return;
    }
    if(target<0){
        return;
    }

    for(int i=index;i<candidates.size();i++){
        v.push_back(candidates[i]);
        combination(candidates,target-candidates[i],ans,v,i+1,k);
        v.pop_back();
    }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>candidates;
        for(int i=1;i<=9;i++){
            candidates.push_back(i);
        }
        vector<vector<int>>ans;
        vector<int>v;
       combination(candidates,n,ans,v,0,k);
       return ans;
    }
};