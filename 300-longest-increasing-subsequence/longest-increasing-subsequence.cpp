class Solution {
public:
    int solve(int ind,vector<int>&nums,int pre_ind){
        if(ind==nums.size()) return 0;

        int len=solve(ind+1,nums,pre_ind);
        if(pre_ind==-1 || nums[ind]>nums[pre_ind]){
            len=max(len,1+solve(ind+1,nums,ind));
        }
        return len;
    }
    
    int topdown(int ind,vector<int>&nums,int pre_ind,vector<vector<int>>&dp){
        if(ind==nums.size()) return 0;
        if(dp[ind][pre_ind+1]!=-1) return dp[ind][pre_ind+1];
        int len=topdown(ind+1,nums,pre_ind,dp);
        if(pre_ind==-1 || nums[ind]>nums[pre_ind]){
            len=max(len,1+topdown(ind+1,nums,ind,dp));
        }
        return dp[ind][pre_ind+1]=len;
    }

    int bottomup(int n,vector<int>&nums,int pre_ind,vector<vector<int>>&dp){
        
        for(int ind=n-1;ind>=0;ind--){
            for(int pre_ind=ind-1;pre_ind>=-1;pre_ind--){
                int len=dp[ind+1][pre_ind+1];
                if(pre_ind==-1 || nums[ind]>nums[pre_ind]){
                    len=max(len,1+dp[ind+1][ind+1]);
                }
                dp[ind][pre_ind+1]=len;
            } 
        }
        return dp[0][0];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // return solve(0,nums,-1);

        //top down dp
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return topdown(0,nums,-1,dp);

        //bottomup dp
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        return bottomup(n,nums,-1,dp);
    }
};