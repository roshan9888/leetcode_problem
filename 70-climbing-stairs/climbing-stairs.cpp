class Solution {
public:
    // int solve(int n ,int &count){
    //     if(n==1 || n==0){
    //         count++;
    //         return n;
    //     }

    //     solve(n-1,count)+solve(n-2,count);
    //     return count;
    // }

    int topdown(int n,vector<int>&dp){
        if(n==1) return 1;
        if(n==0) return 1;

        if(dp[n]!=-1){
            return dp[n];
        }

        return dp[n]=topdown(n-1,dp)+topdown(n-2,dp);
    }

    int climbStairs(int n) {
        // int count=0;
        // return solve(n,count);

        //top down dp
        vector<int>dp(n+1,-1);
        return topdown(n,dp);
    }
};