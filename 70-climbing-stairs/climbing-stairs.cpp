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

    void bottomup(int n,vector<int>&dp){
        dp[0]=1;
        dp[1]=1;

        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
    }

    int climbStairs(int n) {
        // int count=0;
        // return solve(n,count);

        //top down dp
        // vector<int>dp(n+1,-1);
        // return topdown(n,dp);

        //botto up dp
        vector<int>dp(n+1,-1);
        bottomup(n,dp);
        return dp[n];
    }
};