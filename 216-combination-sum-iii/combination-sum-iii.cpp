class Solution {
public:
    void solve(vector<int>&nums,int ind,int target,int k,vector<vector<int>>&ans,vector<int>temp){
        if(target==0 && temp.size()==k){
            ans.push_back(temp);
        }

        for(int i=ind;i<nums.size();i++){
            if(ind!=i && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(nums,i+1,target-nums[i],k,ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums{1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>temp;
        solve(nums,0,n,k,ans,temp);
        return ans;
    }
};