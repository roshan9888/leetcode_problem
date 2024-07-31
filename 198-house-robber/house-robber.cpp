class Solution {
public:
    int solve(int ind,vector<int>&nums){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;

        int pick=nums[ind]+solve(ind-2,nums);
        int notpick=solve(ind-1,nums);

        return max(pick,notpick);
    }
     
    int topdown(int ind,vector<int>&nums,vector<int>&dp){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;

        if(dp[ind]!=-1) return dp[ind];
        int pick=nums[ind]+topdown(ind-2,nums,dp);
        int notpick=topdown(ind-1,nums,dp);

        return dp[ind]=max(pick,notpick);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        // return solve(n-1,nums);

        //top down dp
        vector<int>dp(n+1,-1);
        return topdown(n-1,nums,dp);
    }
};