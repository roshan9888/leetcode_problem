class Solution {
public:
    void solve(vector<int>&candidates, int target,int ind,vector<vector<int>>&ans,vector<int>&temp){

            if(target==0){
            ans.push_back(temp);
            return;
            }
         
        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(target<candidates[i]) break;
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],i+1,ans,temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
         sort(candidates.begin(),candidates.end());
            solve(candidates,target,0,ans,temp);
        return ans;
    }
};