class Solution {
public:
    int topdown(int ind,int sum,vector<int>&arr,vector<vector<int>>&dp){
        if(ind==0){
            if(sum==0 && arr[0]==sum) return 2;
            if(sum==0 || arr[0]==sum) return 1;
            return 0;
        }
        
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int notpick=topdown(ind-1,sum,arr,dp);
        int pick=0;
        if(arr[ind]<=sum){
             pick=topdown(ind-1,sum-arr[ind],arr,dp);
        }
        return dp[ind][sum]=(notpick+pick);
    }

    int findTargetSumWays(vector<int>&nums, int target) {
        int totsum=0;
        int n=nums.size();
        for(int i=0;i<n;i++) totsum+=nums[i];
        if((totsum-target)<0 || (totsum-target)%2) return 0;
        int sum=(totsum-target)/2;
        
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return topdown(n-1,sum,nums,dp);
    }
};