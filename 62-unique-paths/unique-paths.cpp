class Solution {
public:
    int solve(int i,int j){
        if(i==0 && j==0){
            return 1;
        }

        if(i<0 || j<0) return 0;

        int left=solve(i,j-1);
        int right=solve(i-1,j);
        return left+right;
    }

    int topdown(int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0){
            return 1;
        }

        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j]; 
        int left=topdown(i,j-1,dp);
        int right=topdown(i-1,j,dp);
        return dp[i][j]=left+right;
    }

    int uniquePaths(int m, int n) {
        // return solve(m-1,n-1);
        
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return topdown(m-1,n-1,dp);
    }
};