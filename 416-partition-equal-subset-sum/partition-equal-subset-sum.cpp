class Solution {
public:
    bool solve(int ind,int target,vector<int>&arr){
        if(target==0) return true;
        if(ind==0) return (arr[0]==target);
        
        bool nottake=solve(ind-1,target,arr);
        bool take;
        if(target>=arr[ind]){
            take=solve(ind-1,target-arr[ind],arr);
        }
        
        return take||nottake;
    }
    
    bool topdown(int ind,int target,vector<int>&arr,vector<vector<int>>&dp){
        if(target==0) return true;
        if(ind==0) return (arr[0]==target);
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool nottake=topdown(ind-1,target,arr,dp);
        bool take;
        if(arr[ind]<=target){
            take=topdown(ind-1,target-arr[ind],arr,dp);
        }
        
        return dp[ind][target]=take|nottake;
    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        if(sum%2){
            return false;
        }
        int target=sum/2;
        // return solve(nums.size()-1,target,nums);

        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        return topdown(nums.size()-1,target,nums,dp);
    }
};