class Solution {
public:
    int solve(vector<int>&coins,int target,int i){
        if(i==0){
        if(target%coins[i]==0){
            return target/coins[i];
        }else{
            return 1e8;
        }
        }
        
        int notpick=solve(coins,target,i-1);
        int pick=1e8;
        if(coins[i]<=target){
            pick=1+solve(coins,target-coins[i],i);
        }
        return min(pick,notpick);
    }
    
    int topdown(vector<int>&coins,int target,int i,vector<vector<int>>&dp){
        if(i==0){
        if(target%coins[i]==0){
            return target/coins[i];
        }else{
            return 1e8;
        }
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int notpick=topdown(coins,target,i-1,dp);
        int pick=1e8;
        if(coins[i]<=target){
            pick=1+topdown(coins,target-coins[i],i,dp);
        }
        return dp[i][target]=min(pick,notpick);
    }
    
    int bottomup(vector<int>&coins,int target,int n,vector<vector<int>>&dp){
        for(int t=0;t<=target;t++){
            if(t%coins[0]==0){
                dp[0][t]=t/coins[0];
            }
            else{
                dp[0][t]=1e8;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int t=0;t<=target;t++){
                    int notpick=dp[i-1][t];
                    int pick=1e8;
                    if(coins[i]<=t){
                        pick=1+dp[i][t-coins[i]];
                    }
                    dp[i][t]=min(pick,notpick);
            }
        }
        return dp[n-1][target];
    }

    int space(vector<int>&coins,int target,int n){
        vector<int>prev(target+1,0),curr(target+1,0);
        for(int t=0;t<=target;t++){
            if(t%coins[0]==0){
                prev[t]=t/coins[0];
            }
            else{
                prev[t]=1e8;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int t=0;t<=target;t++){
                    int notpick=prev[t];
                    int pick=1e8;
                    if(coins[i]<=t){
                        pick=1+curr[t-coins[i]];
                    }
                    curr[t]=min(pick,notpick);
            }
            prev=curr;
        }
        return prev[target];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        // int ans=solve(coins,amount,n-1);
        // return ans==1e8?-1:ans;

        // vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        // int ans=topdown(coins,amount,n-1,dp);
        // return ans==1e8?-1:ans;

        // vector<vector<int>>dp(n,vector<int>(amount+1,0));
        // int ans=bottomup(coins,amount,n,dp);
        // return (ans>=1e8)?-1:ans;

        int ans=space(coins,amount,n);
        return (ans>=1e8)?-1:ans;
    }
};