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

    int bottomup(int ind,vector<int>&nums,vector<int>&dp){
        dp[0]=nums[0];
         
        for(int i=1;i<=ind;i++){
            int pick=nums[i];
            if(i>1) pick+=dp[i-2];
            int notpick=dp[i-1];

            dp[i]=max(pick,notpick);
        }
        return dp[ind];
    }

    int space(int ind,vector<int>&nums){
        if(ind==0) return nums[0];
        int prev=nums[0];
        int prev2,curr;
        for(int i=1;i<=ind;i++){
            int pick=nums[i];
            if(i>1) pick+=prev2;
            int notpick=prev;

            curr=max(pick,notpick);

            prev2=prev;
            prev=curr;
        }
        return curr;
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        // return solve(n-1,nums);

        //top down dp
        // vector<int>dp(n+1,-1);
        // return topdown(n-1,nums,dp);
        
        //bottom up dp
        // vector<int>dp(n+1,0);
        // return bottomup(n-1,nums,dp);

        //space
        return space(n-1,nums);
    }
};