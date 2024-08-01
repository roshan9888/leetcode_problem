class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&grid){
        if(i==0 && j==0) return grid[0][0];

        if(i<0 || j<0) return INT_MAX;
        int mini=0;
        int left=solve(i,j-1,grid);
        if(left!=INT_MAX){
            left+=grid[i][j];
        }
        int up=solve(i-1,j,grid);
        if(up!=INT_MAX){
            up+=grid[i][j];
        }
        mini=min(left,up);
        return mini;
    }

    int topdown(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i==0 && j==0) return grid[0][0];

        if(i<0 || j<0) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=0;
        int left=topdown(i,j-1,grid,dp);
        if(left!=INT_MAX){
            left+=grid[i][j];
        }
        int up=topdown(i-1,j,grid,dp);
        if(up!=INT_MAX){
            up+=grid[i][j];
        }
        mini=min(left,up);
        return dp[i][j]=mini;
    }
    
    int bottomup(int m,int n,vector<vector<int>>&grid,vector<vector<int>>&dp){
        int mini=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[0][0]=grid[0][0];
                else{
                  int left=j>0?grid[i][j]+dp[i][j-1] : INT_MAX;
                  int up=i>0?grid[i][j]+dp[i-1][j]:INT_MAX;
                  dp[i][j]=min(left,up);
                }
                
            }
        }
        return dp[m-1][n-1];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // return solve(m-1,n-1,grid);

        //top down dp
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return topdown(m-1,n-1,grid,dp);

        //bottomup dp
        vector<vector<int>>dp(m,vector<int>(n,0));
        return bottomup(m,n,grid,dp);
    }
};